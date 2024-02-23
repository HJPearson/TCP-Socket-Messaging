#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "../../include/server.h"
#include "../../include/tcpCommunication.h"


// Simple declarations for the constructor and destructor
TcpServer::TcpServer(std::string ipv4_address) {
    ipv4 = ipv4_address;
}
TcpServer::~TcpServer() {}

/*
* Function for starting the server, which consists of:
*    - Creating a socket
*    - Setting the port and IPv4
*    - Binding the socket to the port/IPv4
*    - Making the socket listen for a connection
*    - Calling the establishConnection() function to accept and handle communication with the client
*/
void TcpServer::startServer() {
    // Create the socket for our server. Since we want to use TCP, we use SOCK_STREAM
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    // Set our port to 50000 and our IPv4
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(50000);
    socket_address.sin_addr.s_addr = inet_addr(ipv4.c_str());
    // Convert an IPv4 from a string to binary
    if (inet_pton(AF_INET, ipv4.c_str(), &socket_address.sin_addr) != 1) {
        perror("Failed to convert IP address to binary");
        exit(EXIT_FAILURE);
    }
    // Bind the socket to an IPv4
    if (bind(socket_fd, (struct sockaddr *) &socket_address, sizeof(socket_address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    std::cout << "Socket bound to address " << socket_address.sin_addr.s_addr << std::endl;
    // Finally, make the socket listen for connections
    if (listen(socket_fd, SOMAXCONN) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    std::cout << "Server is up and listening." << std::endl;
    establishConnection();
}

/*
* Function for closing the server once communication has ceased
*/
void TcpServer::closeServer() {
    // Shut down the socket
    if (close(socket_fd) == -1) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}

/*
* Function for handling connection with the client, which consists of:
*   - Accepting a connection and creating a new file descriptor for communication
*   - Sending an initial message veryifying successful connection
*   - Allowing threaded communication with the client via the communicate() function
*   - Closing the socket
*/
void TcpServer::establishConnection() {
    // Create new socket for the client connection
    int new_client_socket_fd;
    if ((new_client_socket_fd = accept(socket_fd, (struct sockaddr *)&socket_address, (socklen_t *)&socket_address)) == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    // Send a message to the client that the connection was successful
    const std::string connection_message = "Connection established successfully.\n";
    ssize_t bytes_sent;
    if ((bytes_sent = send(new_client_socket_fd, connection_message.c_str(), connection_message.length(), 0)) == -1) {
        perror("Failed to send connection confirmation");
    }
    // Print the success message to the server
    std::cout << connection_message << std::endl;
    // Communicate with any clients
    communicate(new_client_socket_fd);
    // Close the socket
    if (close(new_client_socket_fd) == -1) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}
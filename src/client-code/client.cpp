#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../../include/client.h"
#include "../../include/tcpCommunication.h"


Client::Client(){}
Client::~Client(){}

/*
* Function for connecting to a server, which consists of:
*   - Creating a socket file descriptor
*   - Setting the IPv4 address and port number
*   - Connecting to the server via the connect() function
*   - Communicating with the server via the communicate() function
*   - Closing the socket
*/
void Client::connectToServer(std::string ip_address) {
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_port = htons(50000);
    server_socket_address.sin_addr.s_addr = inet_addr(ip_address.c_str());
    if (connect(socket_fd, (struct sockaddr *) &server_socket_address, sizeof(server_socket_address)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    // Communicate with the server
    communicate(socket_fd);
    if (close(socket_fd) == -1) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}
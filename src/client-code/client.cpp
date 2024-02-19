#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../../include/client.h"


Client::Client(){}
Client::~Client(){}

void Client::connect_to_server() {
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    // ipv4 = "10.21.31.47";
    ipv4 = "127.0.0.1";
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_port = htons(50000);
    server_socket_address.sin_addr.s_addr = inet_addr(ipv4);
    if (connect(socket_fd, (struct sockaddr *) &server_socket_address, sizeof(server_socket_address)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    ssize_t message_from_server;
    ssize_t bytes_sent;
    while ((message_from_server = recv(socket_fd, &buffer, sizeof(buffer), 0)) > 0) {
        // Null terminate the string
        buffer[message_from_server] = '\0';
        std::cout << buffer << std::endl;
        // Get input from user running the server and send it to the client
        std::cout << "You may send a message to the server" << std::endl;
        std::string message_to_server;
        std::getline(std::cin, message_to_server);
        if ((bytes_sent = send(socket_fd, message_to_server.c_str(), message_to_server.length(), 0)) == -1) {
            perror("Failed to send message");
            exit(EXIT_FAILURE);
        }
    }
    if (close(socket_fd) == -1) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}
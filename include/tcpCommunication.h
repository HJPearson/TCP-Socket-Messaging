#ifndef TCPCOMMUNICATION_H
#define TCPCOMMUNICATION_H

#include <iostream>
#include <thread>
#include <sys/socket.h>


/*
* Function handling the sending of messages
*/
void sendMessage(int socket_file_descriptor) {
    ssize_t bytes_sent;
    while (true) {
        // Prompt user for input and send message
        std::string message_to_client;
        std::getline(std::cin, message_to_client);
        if ((bytes_sent = send(socket_file_descriptor, message_to_client.c_str(), message_to_client.length(), 0)) == -1) {
            perror("Failed to send message");
        }
    }
}

/*
* Function handling the receiving of messages
*/
void receiveMessage(int socket_file_descriptor) {
    ssize_t message_from_client;
    while (true) {
        // Buffer to store message from client
        char buffer[1024];
        if ((message_from_client = recv(socket_file_descriptor, &buffer, sizeof(buffer), 0)) < 1) {
            perror("Recieve failed");
            if (close(socket_file_descriptor) == -1) {
                perror("Failed to close socket");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        } else {
            std::string received_message(buffer, message_from_client);
            // Prepend "Them" to the message to make viewing message history in the terminal more clear
            std::cout << "Them: " << received_message << std::endl;
        }
    }
}

/*
* Function that handles general, threaded communication
*/
void communicate(int socket_file_descriptor) {
    std::thread t_recv(receiveMessage, socket_file_descriptor);
    std::thread t_send(sendMessage, socket_file_descriptor);
    t_recv.join();
    t_send.join();
}
#endif
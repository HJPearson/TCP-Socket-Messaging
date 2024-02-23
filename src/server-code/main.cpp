#include <iostream>
#include <arpa/inet.h>
#include "../../include/server.h"


int main() {
    std::cout << "What IPv4 address do you want to host the server? Enter 'localhost' to use the localhost IPv4, or type in a custom IPv4." << std::endl;
    std::string ip_address;
    std::cin >> ip_address;
    if (ip_address == "localhost") {
        ip_address = "127.0.0.1";
    }
    // Start server
    TcpServer server(ip_address);
    server.startServer();

    // Close server
    server.closeServer();

    return 0;
}
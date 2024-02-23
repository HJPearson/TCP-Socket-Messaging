#include <iostream>
#include "../../include/client.h"

int main() {
    // Prompt the user for an IPv4 address
    std::cout << "What is the IPv4 address of the server you wish to connect to? Enter 'localhost' to use the localhost IPv4, or type in a custom IPv4." << std::endl;
    std::string ip_address;
    std::cin >> ip_address;
    if (ip_address == "localhost") {
        ip_address = "127.0.0.1";
    }
    // Start server
    Client client;
    client.connectToServer(ip_address);

    return 0;
}
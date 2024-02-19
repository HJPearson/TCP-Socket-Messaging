#include <iostream>
#include "../../include/client.h"

int main() {
    // Start server
    Client client;
    client.connect_to_server();
    
    // Wait for user input
    // char user_input;
    // std::cin >> user_input;
    // while (std::toupper(user_input) != 'Q');

    return 0;
}
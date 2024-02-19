#include <iostream>
#include "../../include/server.h"


int main() {
    // Start server
    TcpServer server;
    server.startServer();

    // Wait for user input and loop until the ` key is pressed
    // char user_input;
    // std::cin >> user_input;
    // while (user_input != '`');

    // Close server
    server.closeServer();

    return 0;
}
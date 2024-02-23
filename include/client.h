#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>

class Client {
    public:
        Client();
        ~Client();
        void connectToServer(std::string ip_address);
    private:
        int socket_fd;                        // Socket file descriptor
        sockaddr_in server_socket_address;
};

#endif
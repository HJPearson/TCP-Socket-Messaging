#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>

class Client {
    public:
        Client();
        ~Client();
        void connect_to_server();


    private:
        int socket_fd;                        // Socket file descriptor
        sockaddr_in server_socket_address;
        const char *ipv4;                     // IPv4 adress

};

#endif
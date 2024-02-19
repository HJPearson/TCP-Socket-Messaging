#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>


class TcpServer {
    public:
        TcpServer();
        ~TcpServer();
        void startServer();
        void closeServer();
        void communicate();
    private:
        int socket_fd;                 // Socket file descriptor
        sockaddr_in socket_address;
        const char *ipv4;              // IPv4 adress
};
#endif
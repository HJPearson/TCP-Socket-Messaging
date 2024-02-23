#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>


class TcpServer {
    public:
        TcpServer(std::string ipv4_address);
        ~TcpServer();
        void startServer();
        void closeServer();
        void establishConnection();
    private:
        int socket_fd;                 // Socket file descriptor
        sockaddr_in socket_address;
        std::string ipv4;              // IPv4 adress
};
#endif
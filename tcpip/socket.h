#ifndef __TCPIP_HEADER__
#define __TCPIP_HEADER__

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <memory>
#include <cstring>
#include <unistd.h>

int const ERROR_SOCKET = -1;

class Sock{
private:
    int sock;

    friend class std::unique_ptr<Sock>;
    std::unique_ptr<Sock> ConnectedSock;

    Sock(int SockID,sockaddr_in& addr);
protected:
    sockaddr_in addr;  
    bool SetConnectedSock(int SockID,sockaddr_in& addr);
public:
    Sock(std::string Protocol);
    virtual ~Sock();

    bool Socket(int af = PF_INET,int type = SOCK_STREAM,int protocol = 0);
    void Close();

    int GetSock() const;

    bool SetIP(std::string IP);
    std::string GetIP() const;
    
    virtual bool isLive() const;
    virtual bool isConnected() const;

    virtual ssize_t Send(const void * buffer,size_t length,int flags = 0);
    virtual ssize_t Recv(void * buffer,size_t length,int flags = 0);
};

#endif

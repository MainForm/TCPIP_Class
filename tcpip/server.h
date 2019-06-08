#ifndef __SERVER_HEADR__
#define __SERVER_HEADR__

#include "socket.h"

int const ERROR_BIND = -2;
int const ERROR_LISTEN = -3;

class Server : public Sock{
private:
    bool Bind();
    bool Listen(int backlog = 5);
public:
    Server(std::string Port);
    int Open(int backlog = 5);

    bool Accept();
    void Disconnect();
};

#endif

#ifndef __CLIENT_HADER__
#define __CLIENT_HADER__

#include "socket.h"
#include "server.h"

class Client : public Sock{
private:

public:
    Client(std::string IP,std::string Port);
    
    bool Connect();
};

#endif

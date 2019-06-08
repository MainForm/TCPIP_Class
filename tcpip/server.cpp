#include "server.h"

Server::Server(std::string Port):Sock(Port){
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

//below code is private
bool Server::Bind(){
    if(bind(GetSock(),(sockaddr*)&addr,sizeof(addr)) == -1)
        return false;

    return true;
}

bool Server::Listen(int backlog){
    if(listen(GetSock(),backlog) == -1)
        return false;

    return true;
}


//below code is public
int Server::Open(int backlog){
    if(!Socket())
        return ERROR_SOCKET;
    if(!Bind())
        return ERROR_BIND;
    if(!Listen(backlog))
        return ERROR_LISTEN;

    return 1;
}

bool Server::Accept(){
    int Client_Sock = 0;
    sockaddr_in Client_addr;
    socklen_t Client_addr_size = sizeof(Client_addr);

    Client_Sock = accept(this->GetSock(),(struct sockaddr*)&Client_addr,&Client_addr_size);
    if(Client_Sock == 0)
        return false;

    this->SetConnectedSock(Client_Sock,Client_addr);

    return true;
}

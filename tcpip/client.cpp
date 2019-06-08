#include "client.h"

Client::Client(std::string IP,std::string Port):Sock(Port){
    SetIP(IP);
    Socket();
}

bool Client::Connect(){
    if(connect(GetSock(),(struct sockaddr*)&addr,sizeof(addr)) == -1)
        return false;
    
    
    return true;
}

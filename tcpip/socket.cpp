#include "socket.h"

//this constructo is used for only make_unique function
Sock::Sock(int sock,sockaddr_in& addr):sock(sock),addr(addr){}

Sock::Sock(std::string Port){
    sock = -1;
    memset(&addr,0,sizeof(addr));
    addr.sin_port = htons(atoi(Port.c_str()));
    addr.sin_family = AF_INET;
}

Sock::~Sock(){
    Close();
}

int Sock::GetSock() const{
    return sock;
}

bool Sock::SetIP(std::string IP){
    if(!inet_aton(IP.c_str(),&addr.sin_addr))
        return false;

    return true;
}

std::string Sock::GetIP() const{
    return std::string(inet_ntoa(addr.sin_addr));
}

bool Sock::Socket(int af,int type,int protocol){
    Close();

    sock = socket(af,type,protocol);
    
    if(sock == -1)
        return false;
    
    return true;
}

void Sock::Close(){
    ConnectedSock.release();
    
    if(sock != -1){
        if(close(sock) == 0){
            sock = -1;
        }
        else{
            std::cerr<<"close() error is occured!\n";
            sock = -2;
        }
    }
}

bool Sock::isLive() const{
    if(sock == -1)
        return false;
    
    return true;
}

bool Sock::isConnected() const{
    if(ConnectedSock == nullptr)
        return false;

    return true;
}

bool Sock::SetConnectedSock(int SockID,sockaddr_in& addr){
    if(this->isLive() == false)
        return true;

    ConnectedSock.reset(new Sock(SockID,addr));
    
    return false;
}

ssize_t Sock::Send(const void * buffer,size_t length,int flags){
    if(!isConnected())
        return -10;
    return send(ConnectedSock->GetSock(),buffer,length,flags);
}

ssize_t Sock::Recv(void * buffer,size_t length,int flags){
    if(!isConnected())
        return -10;

    return recv(ConnectedSock->GetSock(),buffer,length,flags);
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

void error_handling(string message);

int main(int argc,char *argv[]){
    int sock;
    struct sockaddr_in serv_addr;
    string message;
    int str_len;

    if(argc != 3){
        cout<<"usage : "<<argv[0]<<" <IP> <PORT>\n"<<endl;
        exit(1);
    }

    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
        error_handling("connect() error!");
    
    message.resize(30);
    str_len = read(sock,(void *)&message.front(),message.size()-1);
    if(str_len ==-1)
        error_handling("read() error!");
    
    message[str_len] = 0;
    cout<<"Message form server : "<<message<<"\nend of line"<<endl;
    close(sock);

    return 0;
}

void error_handling(string message){
    fputs(message.data(),stderr);
    fputc('\n',stderr);
    exit(1);
}

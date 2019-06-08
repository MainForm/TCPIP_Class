#include <iostream>
#include "tcpip/client.h"

using namespace std;

int main(void){
    Client clnt("127.0.0.1","7894");

    if(!clnt.Connect())
        cout<<"Connect() is error"<<endl;

    return 0;
}

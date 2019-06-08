#include <iostream>
#include "tcpip/server.h"

using namespace std;

int main(void){
    Server Test("7894");

    if(Test.Open()<0)
        cout<<"Error is occured in Open() function!"<<endl;

    cout<<"SockID :"<<Test.GetSock()<<endl;
    
    Test.Accept();
    

    cout<<"Some Computer is connected!"<<endl;
    return 0;
}

#include <iostream>
#include "Socket.h"

#include "MPointer.h"
#include "MPointer.cpp"
#include "json.hpp"

using json = nlohmann::json;

int main() {


/*


    ClientSocket *client = new ClientSocket(5555,"172.18.29.44");

    int n = 100;
    client->requestMemory(n);
    while(n > 0) {
        std::cout<<client->saveValue(n)<<std::endl;
        n--;
    }
    n = 99;
    while(n >= 0) {
        std::cout<<client->getValue(n)<<std::endl;
        n--;
    }
    n = 99;
    while (n >= 0){
        client->changeValue(n,n);
        n--;
    }
    n = 99;
    while (n >= 0){
        client->removeValue(n);
        n--;
    }


*/
    MPointer<int> mPointer = MPointer<int>();
    mPointer.MPointer_init(5555,"192.168.0.104",10);

    mPointer = 5;

    return 0;
}

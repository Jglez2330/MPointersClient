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
    MPointer<int> mPointer1;
    mPointer.MPointer_init(5555,"172.19.49.251",10);
    mPointer.New();
    mPointer1.New();


    mPointer = 1;
    mPointer1= mPointer;
    std::cout<<*mPointer1 << std::endl;
    std::cout<<*mPointer << std::endl;


    return 0;
}

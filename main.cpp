#include <iostream>
#include "Socket.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {

    auto j = json::parse("{\"opcode\":0,\"size\":5}");
    json json1;
    json json2;
    int opcode = 0;



    ClientSocket *client = new ClientSocket(5555,"192.168.0.104");

    int n = 10;
    client->requestMemory(10);
    while(n > 0) {
        std::cout<<client->saveValue(n)<<std::endl;
        n--;
    }
    n = 9;
    while(n >= 0) {
        std::cout<<client->getValue(n)<<std::endl;
        n--;
    }
    n = 9;
    while (n >= 0){
        client->changeValue(n,n);
        n--;
    }
    n = 9;
    while (n >= 0){
        client->removeValue(n);
        n--;
    }




    return 0;
}

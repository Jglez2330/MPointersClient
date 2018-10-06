#include <iostream>
#include "Socket.h"

#include "MPointer.h"
#include "MPointer.cpp"
#include "json.hpp"

using json = nlohmann::json;

int main() {

    MPointer<int> mPointer = MPointer<int>();
    MPointer<int> mPointer1;
    mPointer.MPointer_init(5555,"10.10.10.110",10);
    mPointer.New();
    mPointer1.New();


    mPointer = 1;
    mPointer1= 10;
    std::cout<<*mPointer1 << std::endl;
    std::cout<<*mPointer << std::endl;


    return 0;
}

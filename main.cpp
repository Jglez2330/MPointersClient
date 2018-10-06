#include <iostream>
#include "Socket.h"

#include "MPointer.h"
#include "MPointer.cpp"
#include "json.hpp"
#include "DoubleLInkedList.cpp"

using json = nlohmann::json;

int main() {
int cantElements = 100;
MPointer<int>::MPointer_init(5555,"10.10.10.110",cantElements);

MPointer<int> mPointer;
MPointer<int> mPointer1;
MPointer<int> mPointer2;
MPointer<int> mPointer3;

mPointer.New();
mPointer1.New();
mPointer2.New();
mPointer3.New();

mPointer =  2;
mPointer1 = 127;
mPointer2 = 44;
mPointer3 = 92;

mPointer = mPointer1;
mPointer = 14;

std::cout << *mPointer<< std::endl;
std::cout << *mPointer1 << std::endl;


    return 0;
}

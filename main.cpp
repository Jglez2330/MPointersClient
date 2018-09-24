#include <iostream>
#include "Socket.h"

int main() {


    ClientSocket *client = new ClientSocket(5555,"10.10.10.110");
    return 0;
}

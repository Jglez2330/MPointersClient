//
// Created by Fabricio ELizondo on 27/09/18.
//

#ifndef MPOINTERS_NODEGC_H
#define MPOINTERS_NODEGC_H

#include "MPointer.h"


template <typename T>

class NodeGC{

public:

    NodeGC(MPointer<T>* ptrAddres);

private:

    NodeGC<T>* next;
    MPointer<T>* memoryAddres;
    static int counter;
    int ID_GC;

    template <typename U> friend class LinkedListGC;

};

#endif //MPOINTERS_NODEGC_H

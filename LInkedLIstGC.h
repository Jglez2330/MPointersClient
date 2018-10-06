//
// Created by Fabricio ELizondo on 27/09/18.
//

#ifndef MPOINTERS_LINKEDLISTGC_H
#define MPOINTERS_LINKEDLISTGC_H

#include "NodeGC.h"
#include "NodeGC.cpp"



template <typename T>


class LinkedListGC{

public:

    LinkedListGC(){first = current = NULL;};
    ~LinkedListGC();

    bool emptyList(){return first == NULL;};
    int add(MPointer<T>* ptrAddres);
    void remove(int Id);
    MPointer<T>* getAddres(int Id);
    void printList();

private:

    NodeGC<T>* first;
    NodeGC<T>* current;
};

#endif //MPOINTERS_LINKEDLISTGC_H

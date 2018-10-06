//
// Created by Fabricio ELizondo on 5/10/18.
//

#ifndef MPOINTERS_NODELD_H
#define MPOINTERS_NODELD_H

#include "MPointer.h"

template <typename T>
class NodeLD{

public:

    NodeLD(MPointer<T> ptr);

private:

    NodeLD<T>* next;
    NodeLD<T>* previous;
    MPointer<T> mPointer;

    template <typename U> friend class DoubleLinkedList;



};

#endif //MPOINTERS_NODELD_H

//
// Created by Fabricio ELizondo on 5/10/18.
//

#include "NodeLD.h"

template <typename T>
NodeLD<T>::NodeLD(MPointer<T> ptr) {

    mPointer.New();
    mPointer = ptr;
    mPointer.getRC()->addRef();
    next = NULL;
    previous = NULL;
}


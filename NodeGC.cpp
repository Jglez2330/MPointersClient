//
// Created by Fabricio ELizondo on 27/09/18.
//

#include "NodeGC.h"

template <typename T>
int NodeGC<T>::counter = 0;

template <typename T>
NodeGC<T>::NodeGC(MPointer<T>* ptrAddres) {

    memoryAddres = ptrAddres;
    next = NULL;
    counter++;
    ID_GC = counter;
}

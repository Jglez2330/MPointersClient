//
// Created by user on 3/10/18.
//

#include "ReferenceCounter.h"

void ReferenceCounter::addRef() {

    counter++;
}

int ReferenceCounter::Release() {

    return --counter;
}
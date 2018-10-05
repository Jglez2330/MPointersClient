//
// Created by ferathor on 18/09/18.
//



#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include "ReferenceCounter.h"
#include "Socket.h"
#include <iostream>

template <typename T>

class MPointer {

public:

    MPointer();
    MPointer(T nVal);
    void New();
    ~MPointer();
    T& operator*();
    T* operator&();
    MPointer<T>& operator=(const MPointer<T>& myPtr);
    template <typename U> void operator=(U data);
    int getId();
    T getValue();
    ReferenceCounter* getRC();
    T* getPointerValue();


    static bool isClientActive;

    static int MPointer_init(int port,char* ip, int cabtElements);

private:

    static ClientSocket *clientSocket;
    T* val;
    MPointer<T>* ptr;
    int ID_GC;
    ReferenceCounter* referenceCounter;
};


#endif //MPOINTER_MPOINTER_H

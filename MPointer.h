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
    T getValue() const;
    ReferenceCounter* getRC();
    T* getPointerValue();
    static bool isClientActive;
    static ClientSocket *clientSocket;
    static int MPointer_init(int port,char* ip, int cantElements);
    inline bool operator==(const MPointer<T>& myPtr);
    inline bool operator!=(const MPointer<T>& myPtr);
    inline bool operator <(const MPointer<T>& myPtr);
    inline bool operator >(const MPointer<T>& myPtr);
    inline bool operator <=(const MPointer<T>& myPtr);
    inline bool operator >=(const MPointer<T>& myPtr);


private:

    T* val;
    MPointer<T>* ptr;
    bool fVal;
    int idServer;
    int ID_GC;
    ReferenceCounter* referenceCounter;
};


#endif //MPOINTER_MPOINTER_H

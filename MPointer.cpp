//
// Created by ferathor on 18/09/18.
//

#include "MPointer.h"
#include <cstdlib>
//#include "GarbageCollector.h"

template <typename T>
bool MPointer<T>::isClientActive = false;
template <typename T>
MPointer<T>::MPointer() {
    /*this->ptr = this;
    GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    this->ID_GC = gcInstance->addMPointer(this->ptr);
    referenceCounter = new ReferenceCounter();
    referenceCounter->addRef();
    this->val = (T*) malloc (sizeof(T));*/


}

template <typename T>
MPointer<T>::MPointer(T nVal) {
    this->ptr = this;
    this->val = (T*) malloc(sizeof(T));
    *this->val = nVal;
    //GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    //this->ID_GC = gcInstance->addMPointer(this->ptr);
    referenceCounter = new ReferenceCounter();
    referenceCounter->addRef();

}

template <typename T>
void MPointer<T>::New() {
    this->ptr = this;
    //GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    //this->ID_GC = gcInstance->addMPointer(this->ptr);
    referenceCounter = new ReferenceCounter();
    referenceCounter->addRef();
    this->val = (T*) malloc (sizeof(T));
}

template <typename T>
T& MPointer<T>::operator*() {

    return *this->val;
}

template <typename T>
T* MPointer<T>::operator&() {

    return this->val;
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& myPtr) {

    if(this != myPtr.ptr){

        if(referenceCounter->Release() == 0){

            free(this->val);
            delete referenceCounter;

        }

        this->val = myPtr.val;
        this->referenceCounter = myPtr.referenceCounter;
        this->referenceCounter->addRef();
    }

    return *this;
}

template <typename T>
template <typename U>
void MPointer<T>::operator=( U data) {

    if(typeid(this->getValue()).name() == typeid(data).name()){

        *this->val = data;
        std::cout << "The value has been changed "<< std::endl;
    }

    else{

        std::cout << "The data type does not match "<<  std::endl;
    }

}

template <typename T>
int MPointer<T>::getId() {

    return this->ID_GC;
}

template <typename T>
T MPointer<T>::getValue() {

    return *this->val;
}

template <typename T>
ReferenceCounter* MPointer<T>::getRC() {

    return this->referenceCounter;
}

template <typename T>
T* MPointer<T>::getPointerValue() {

    return this->val;
}

template <typename T>
MPointer<T>::~MPointer() {

    std::cout << "It was called the destructor of "<< this->getId() << std::endl;
    //GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    //gcInstance->cleanMemory(this->getId());


}

template<typename T>
int MPointer<T>::MPointer_init(int port,char* ip, int cantElements) {
    if (!isClientActive){
        clientSocket = new ClientSocket(port,ip);
        clientSocket->requestMemory(cantElements);
    }
    return 0;

}

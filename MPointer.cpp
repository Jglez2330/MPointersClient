//
// Created by ferathor on 18/09/18.
//

#include "MPointer.h"
#include <cstdlib>
#include "GarbageCollector.h"

template <typename T>
bool MPointer<T>::isClientActive = false;
template <typename T>
ClientSocket* MPointer<T>::clientSocket = nullptr;
template <typename T>
MPointer<T>::MPointer(){
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
    GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    this->ID_GC = gcInstance->addMPointer(this->ptr);
    referenceCounter = new ReferenceCounter();
    referenceCounter->addRef();

}

template <typename T>
void MPointer<T>::New() {
    this->ptr = this;
    GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    this->ID_GC = gcInstance->addMPointer(this->ptr);
    referenceCounter = new ReferenceCounter();
    referenceCounter->addRef();
    this->val = (T*) malloc (sizeof(T));
}

template <typename T>
T& MPointer<T>::operator*() {

    if (!isClientActive){
    return *this->val;
    }else{
        int value = clientSocket->getValue(this->idServer);
        T& temp = (T&) value;
        return temp;
    }
}

template <typename T>
T* MPointer<T>::operator&() {

    return this->val;
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& myPtr) {

    if(this != myPtr.ptr){
        if(!isClientActive){
            if(referenceCounter->Release() == 0) {

                free(this->val);
                delete referenceCounter;
            }
        }else {
            if (!isClientActive) {
                this->val = myPtr.val;
                this->referenceCounter = myPtr.referenceCounter;
                this->referenceCounter->addRef();
            }else{
                this->idServer = myPtr.idServer;
            }
        }
    }

    return *this;
}

template <typename T>
template <typename U>
void MPointer<T>::operator=( U data) {

    if(typeid(this->getValue()).name() == typeid(data).name()){

        if(!isClientActive) {
            *this->val = data;
            std::cout << "The value has been changed " << std::endl;
        }else {
            if (!this->fVal) {
                int temp = (int) data;
                this->idServer = clientSocket->saveValue(temp);
                this->fVal = true;
            } else{
                int temp = (int) data;
                clientSocket->changeValue(this->idServer,temp);
            }
        }
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
    GarbageCollector<T>* gcInstance = GarbageCollector<T>::getInstance();
    gcInstance->cleanMemory(this->getId());


}

template<typename T>
int MPointer<T>::MPointer_init(int port,char* ip, int cantElements) {
    if (!isClientActive){
        isClientActive = true;
        clientSocket = new ClientSocket(port,ip);
        clientSocket->requestMemory(cantElements);
    }
    return 0;

}

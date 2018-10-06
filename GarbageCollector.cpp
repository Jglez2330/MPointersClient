//
// Created by Fabricio Elizondo on 27/09/18.
//

#include "GarbageCollector.h"

template <typename T>
bool GarbageCollector<T>::instanceFLag = false;

template <typename T>
GarbageCollector<T>* GarbageCollector<T>::MPointerGC_Instance = nullptr;

template <typename T>
GarbageCollector<T>::GarbageCollector() {

    this->listGC = new LinkedListGC<T> ();
}

template <typename T>
GarbageCollector<T>* GarbageCollector<T>::getInstance() {

    if(! instanceFLag){
        MPointerGC_Instance = new GarbageCollector();
        instanceFLag = true;
        return MPointerGC_Instance;
    }

    else{
        return MPointerGC_Instance;
    }
}

template <typename T>
int GarbageCollector<T>::addMPointer(MPointer<T>* mpointerAddres) {

    return this->listGC->add(mpointerAddres);

}

template <typename T>
MPointer<T>* GarbageCollector<T>::getMPointer(int Id) {

    return this->listGC->getAddres(Id);
}

template <typename T>
void GarbageCollector<T>::cleanMemory(int Id) {

    MPointer<T>* mpointerAddres = this->listGC->getAddres(Id);

    if(mpointerAddres->getRC()->Release() == 0){

        std::cout << "Memory free"<<std::endl;
        free(mpointerAddres->getPointerValue());
        delete mpointerAddres->getRC();


    }
    else{
        std::cout << "The reference counter is not zero yet"<<std::endl;
    }


}
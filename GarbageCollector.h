//
// Created by Fabricio Elizondo on 27/09/18.
//

#ifndef MPOINTERS_GARBAGECOLLECTOR_H
#define MPOINTERS_GARBAGECOLLECTOR_H

#include "LInkedLIstGC.h"
#include "LInkedLIstGC.cpp"


template <typename T>

class GarbageCollector{

public:

    static GarbageCollector* getInstance();
    ~GarbageCollector(){instanceFLag = false;};
    int addMPointer(MPointer<T>* mpointerAddres);
    MPointer<T>* getMPointer (int Id);
    void cleanMemory(int Id);


private:

    GarbageCollector();
    GarbageCollector (GarbageCollector const&){};
    GarbageCollector& operator=(GarbageCollector const&){};
    static GarbageCollector* MPointerGC_Instance;
    static bool instanceFLag;
    LinkedListGC<T>* listGC;




};

#endif //MPOINTERS_GARBAGECOLLECTOR_H

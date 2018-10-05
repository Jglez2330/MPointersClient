//
// Created by user on 3/10/18.
//

#ifndef MPOINTERS_REFERENCECOUNTER_H
#define MPOINTERS_REFERENCECOUNTER_H

class ReferenceCounter{

public:

    void addRef();
    int Release();

private:

    int counter;
};

#endif //MPOINTERS_REFERENCECOUNTER_H

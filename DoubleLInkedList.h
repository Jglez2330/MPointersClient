//
// Created by Fabricio ELizondo on 5/10/18.
//

#ifndef MPOINTERS_DOUBLELINKEDLIST_H
#define MPOINTERS_DOUBLELINKEDLIST_H

#include "NodeLD.h"
#include "NodeLD.cpp"

template <typename T>
class DoubleLinkedList{

public:

    DoubleLinkedList(){first = current = NULL;};
    ~DoubleLinkedList();

    bool emptyList(){return first == NULL;};
    void add(MPointer<T> ptr);
    NodeLD<T>* lastNode();
    NodeLD<T>* partition(NodeLD<T>* l, NodeLD<T>* h);
    void bubbleSort();
    void quickSort2(NodeLD<T>* l, NodeLD<T>* h);
    void quickSort1();
    void swap(NodeLD<T>* a, NodeLD<T>* b);
    void printList();
    void sortedInsert(NodeLD<T>** head_ref, NodeLD<T>* newNode);
    void insertionSort();

private:

    NodeLD<T>* first;
    NodeLD<T>* current;
};

#endif //MPOINTERS_DOUBLELINKEDLIST_H

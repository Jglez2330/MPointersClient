//
// Created by Fabricio ELizondo on 5/10/18.
//

#include "DoubleLInkedList.h"

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {

    NodeLD<T>* aux;

    while(first){

        aux = first;
        first = first->next;
        delete aux;
    }

    current = NULL;

}

template <typename T>
void DoubleLinkedList<T>::add(MPointer<T> ptr) {


    if(emptyList()){

        first = new NodeLD<T>(ptr);

    }

    else{

        NodeLD<T>* aux = first;

        while(aux->next != NULL){

            aux = aux->next;
        }

        aux->next = new NodeLD<T>(ptr);
        aux->next->previous = aux;

    }
}

template <typename T>
void DoubleLinkedList<T>::printList() {

    NodeLD<T>* aux = first;

    while(aux){

        std::cout << aux->mPointer.getValue() << " -> ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

template <typename T>
void DoubleLinkedList<T>::bubbleSort() {

    int swapped, i;
    NodeLD<T>* ptr1;
    NodeLD<T>* lptr = NULL;

    if(emptyList()){

        return;
    }

    do{

        swapped = 0;
        ptr1 = first;

        while(ptr1 ->next != lptr){

            if(ptr1->mPointer > ptr1->next->mPointer){

                swap(ptr1,ptr1->next);
                swapped = 1;
            }

            ptr1 = ptr1->next;

        }
        lptr = ptr1;

    }
    while(swapped);
}

template <typename T>
void DoubleLinkedList<T>::swap(NodeLD<T>* a, NodeLD<T>* b) {

    MPointer<T> temp;
    temp.New();
    temp = a->mPointer;
    a->mPointer = b->mPointer;
    b->mPointer = temp;
}

template <typename T>
NodeLD<T>* DoubleLinkedList<T>::lastNode() {

    NodeLD<T>* aux = first;

    while(aux->next != NULL){

        aux = aux->next;
    }

    return aux;
}

template <typename T>
NodeLD<T>* DoubleLinkedList<T>::partition(NodeLD<T> *l, NodeLD<T> *h) {

    MPointer<T> x;
    x.New();
    x = h->mPointer;

    NodeLD<T>* i = l->previous;

    for (NodeLD<T>* j = l; j != h; j = j->next){

        if(j->mPointer <= x){

            i = (i == NULL)? l : i->next;
            swap(i, j);

        }

    }
    i = (i == NULL)? l : i->next;
    swap(i,h);
    return i;
}

template <typename T>
void DoubleLinkedList<T>::quickSort2(NodeLD<T> *l, NodeLD<T> *h) {

    if (h != NULL && l != h && l != h->next)
    {
        NodeLD<T>* p = partition(l, h);
        quickSort2(l, p->previous);
        quickSort2(p->next, h);
    }
}

template <typename T>
void DoubleLinkedList<T>::quickSort1() {

    NodeLD<T>* h = this->lastNode();
    this->quickSort2(this->first,h);
}

template <typename T>
void DoubleLinkedList<T>::sortedInsert(NodeLD<T> **head_ref, NodeLD<T> *newNode) {

    NodeLD<T>* current;

    if(*head_ref == NULL){

        *head_ref = newNode;
    }

    else if((*head_ref)->mPointer >= newNode->mPointer){

        newNode->next = *head_ref;
        newNode->next->previous = newNode;
        *head_ref = newNode;

    }

    else{

        current = *head_ref;

        while(current->next != NULL && current->next->mPointer < newNode->mPointer){

            current = current->next;

        }

        newNode->next = current->next;

        if(current->next != NULL ){

            newNode->next->previous = newNode;

        }

        current->next = newNode;
        newNode->previous = current;
    }


}

template <typename T>
void DoubleLinkedList<T>::insertionSort() {


    NodeLD<T>** head_ref = &(first);
    NodeLD<T>* sorted = NULL;
    NodeLD<T>* current = *head_ref;

    while(current != NULL){

        NodeLD<T>* next = current->next;
        current->previous = current->next = NULL;
        sortedInsert(&sorted,current);
        current = next;
    }

    *head_ref = sorted;


}
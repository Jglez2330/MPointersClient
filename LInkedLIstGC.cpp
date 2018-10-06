//
// Created by Fabricio ELizondo on 27/09/18.
//

#include "LInkedLIstGC.h"




template <typename T>
LinkedListGC<T>::~LinkedListGC() {

    NodeGC<T>* aux;

    while(first){

        aux = first;
        first = first->next;
        delete aux;
    }

    current = NULL;
}

template <typename T>
int LinkedListGC<T>::add(MPointer<T>* ptrAddres) {

    if(emptyList()){

        first = new NodeGC<T>(ptrAddres);
        return first->ID_GC;
    }
    else{

        NodeGC<T>* aux = first;
        while(aux->next != NULL){

            aux = aux->next;
        }

        aux->next = new NodeGC<T>(ptrAddres);
        return aux->next->ID_GC;
    }
}

template <typename T>
void LinkedListGC<T>::remove(int Id) {

    NodeGC<T>* aux = first;
    NodeGC<T>* aux2 = NULL;

    if(aux->ID_GC == Id){
        first = first->next;
    }

    else{

        while (aux->ID_GC != Id){

            aux2 = aux;
            aux = aux->next;
        }

        aux2->next = aux2->next->next;
    }




}

template <typename T>
MPointer<T>* LinkedListGC<T>::getAddres(int Id) {

    NodeGC<T>* aux = first;

    while(aux->ID_GC != Id){

        aux = aux->next;
    }

    return aux->memoryAddres;
}

template <typename T>
void LinkedListGC<T>::printList() {

    NodeGC<T>* aux = first;

    while(aux){

        //cout << aux->ID_GC << "->";
        std::cout << aux->memoryAddres << " -> ";
        aux = aux->next;
    }

    std::cout << std::endl;
}
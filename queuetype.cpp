#pragma once
#include "queuetype.h"

template<class T>
QueType<T>::QueType(){
    front = NULL;
    rear = NULL;
}

template<class T>
void QueType<T>::makeEmpty(){
    NodeType *tempPtr;

    while(front){
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
}

template<class T>
QueType<T>::~QueType(){
    makeEmpty();
}

template<class T>
bool QueType<T>::isEmpty(){
    return(!front);
}

template<class T>
bool QueType<T>::isFull(){
    NodeType *location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(bad_alloc& exception){
        return true;
    }
}

template<class T>
void QueType<T>::enqueue(T item){
    if(isFull()){
        throw FullQue();
        return;
    }

    NodeType *newNode;
    newNode = new NodeType;
    newNode->info = item;
    newNode->next = NULL;
    if(!rear) front = newNode;
    else rear->next = newNode;

    rear = newNode;
}

template<class T>
void QueType<T>::dequeue(T& item){
    if(isEmpty()){
        throw EmptyQue();

    }
    else{
      NodeType *tempPtr;
    tempPtr = front;
    item = front->info;
    front = front->next;
    if(!front)
        rear = NULL;
    delete tempPtr;

    }


}

template <class T>
int QueType<T>::lengthIs(){
    int length = 0;
    NodeType *ptr = front;
    while(ptr){
        length++;
        ptr = ptr->next;
    }
    return length;
}


#include "Unosorted_type_linkedlist.h"

template <class T>
UnsortedLinkedList<T>::UnsortedLinkedList(){
    head = NULL;
    currentPos = NULL;
}

template <class T>
void UnsortedLinkedList<T>::resetList(){
    currentPos = NULL;
}

template <class T>
T* UnsortedLinkedList<T>::getNext(){
    if(!currentPos) currentPos = head;
    else currentPos = currentPos->next;

    return currentPos->data;
}

template <class T>
void UnsortedLinkedList<T>::getNextValue(T& v){
    if(currentPos == NULL)
        currentPos = head;
    else
        currentPos = currentPos->next;
    v = currentPos->data;
}

template <class T>
void UnsortedLinkedList<T>::insertItemAtFront(T v){
    Node *newnode;
    newnode = new Node();
    newnode->data = v;

    if(!head)
        head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}

template <class T>
void UnsortedLinkedList<T>::insertItemAtEnd(T v){
    Node* newnode, *n = head;
    newnode = new Node();
    newnode->data = v;
    if(!head)
        head = newnode;
    else{
        while(n->next)
            n = n->next;
        n->next = newnode;
    }

}

template <class T>
void UnsortedLinkedList<T>::insertItemAtMiddle(T v, T p){
    Node *newnode, *n = head;
    newnode = new Node();
    newnode->data = v;

    if(!head)
        head = newnode;
    else{
        while(n->data != p)
            n = n->next;

        newnode->next = n->next;
        n->next = newnode;
    }
}

template <class T>
void UnsortedLinkedList<T>::deleteFromFront(){
    head = head->next;
}

template <class T>
bool UnsortedLinkedList<T>::Search(T p){
    Node *nodeptr = head;

    while(nodeptr){
        if(nodeptr->data == p)
            return true;
        nodeptr = nodeptr->next;
    }return false;
}

template <class T>
void UnsortedLinkedList<T>::deleteFromEnd(){
    Node *n = head, *prev = NULL;

    while(n->next != NULL){
        prev = n;
        n = n->next;
    }

    prev->next = NULL;
}

template <class T>
void UnsortedLinkedList<T>::deleteFromMiddle(T pos){
    Node *n = head, *prev = NULL;
    while(n->data != pos){
        prev = n;
        n = n->next;
    }

    prev->next = n->next;
}

template <class T>
void UnsortedLinkedList<T>::makeListEmpty(){
    Node *temp;

    while(head){
        temp = head->next;
        delete head;
        head = temp;
    }

}

template <class T>
void UnsortedLinkedList<T>::printList(){
    Node *n = head;

    while(n){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}



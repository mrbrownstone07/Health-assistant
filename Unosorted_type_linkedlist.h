#ifndef UNOSORTED_TYPE_LINKEDLIST_H_INCLUDED
#define UNOSORTED_TYPE_LINKEDLIST_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

template <class T>
class UnsortedLinkedList{
    struct Node{
        Node *next;
        T data;
    };

    private:
        Node *head;
        Node *currentPos;

    public:
        UnsortedLinkedList();
        void insertItemAtFront(T);
        void insertItemAtEnd(T);
        void insertItemAtMiddle(T, T);
        void retriveItem(T&, bool&);
        bool Search(T);
        void deleteFromFront();
        void deleteFromEnd();
        void deleteFromMiddle(T);
        void printList();
        void resetList();
        void getNextValue(T&);
        void makeListEmpty();
        T* getNext();

       // void getNextNode(int&);
};


#endif // UNOSORTED_TYPE_LINKEDLIST_H_INCLUDED

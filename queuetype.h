#ifndef QUEUETYPE_H_INCLUDED
#define QUEUETYPE_H_INCLUDED

class FullQue{};
class EmptyQue{};

template <class T>
class QueType{
    struct NodeType{
        T info;
        NodeType *next;
    };

    public:
        QueType();
        ~QueType();
        void makeEmpty();
        void enqueue(T);
        void dequeue(T&);
        bool isEmpty();
        bool isFull();
        int lengthIs();

    private:
        NodeType *front, *rear;
};



#endif // QUEUETYPE_H_INCLUDED

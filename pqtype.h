#ifndef PQTYPE_H_INCLUDED
#define PQTYPE_H_INCLUDED

class FullPQ
{};
class EmptyPQ
{};
template<class ItemType>
class pqtype
{
    public:
        pqtype(int);
        ~pqtype();
        void makeEmpty();
        bool IsEmpty();
        bool IsFull();
        void Enqueue(ItemType);
        void Dequeue(ItemType&);


    private:
        int length;
        heaptype<ItemType> Items;
        int maxItems;
};


#endif // PQTYPE_H_INCLUDED

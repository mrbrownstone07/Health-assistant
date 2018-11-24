#include "pqtype.h"
template<class ItemType>
pqtype<ItemType>::pqtype(int max)
{
    maxItems=max;
    items.elements=new ItemType[max];
    length=0;

}
template<class ItemType>
pqtype<ItemType>::~pqtype();
{
    delete [] items.elements;
}
template<class ItemType>
void pqtype<ItemType>::MakeEmpty()
{
    length = 0;
}
template<class ItemType>
void pqtype<ItemType>::IsEmpty()
{
    return length ==0;
}
template<class ItemType>
void pqtype<ItemType>::IsFull()
{
    return length ==maxItems;
}
template<class ItemType>
void pqtype<ItemType>::Enqueue(ItemType newItem)
{
    if(length==maxItems)
        throw FullPQ();
    else
        {
    length++;
    items.elements[length-1] = newItem;
    items.ReheapUp(0,length-1);
    }
}
template<class ItemType>
void pqtype<ItemType>::Dequeue(ItemType& item)
{
    if(length==0)
        throw EmptyPQ();
    else
    {
    item=items.elements[0];
    items.elements[0]=items.elements[length-1];
    length--;
    items.ReheapDown(0,length-1);
    }
}


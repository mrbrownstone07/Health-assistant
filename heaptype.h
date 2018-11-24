#ifndef HEAPTYPE_H_INCLUDED
#define HEAPTYPE_H_INCLUDED

template<class ItemType>
struct heaptype
{
    void ReheapDown(int root,int bottom);
    void Reheap(int root,int bottom);
    ItemType*elements;
    int numElements;
};



#endif // HEAPTYPE_H_INCLUDED

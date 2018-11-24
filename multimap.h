#ifndef MULTIMAP_H_INCLUDED
#define MULTIMAP_H_INCLUDED
#include <string>

template <class V>
class multimap{
    private:
        struct mapNode{
            string key;
            V value;
            mapNode(string key, V value) : key(key), value(value){}
            mapNode(){
                key = "\0";
            }
            mapNode *next;
        };

        int tableSize;
        mapNode **hashTable;
        int primaryHashCode(string);
        int secondaryHashCode(string);

    public:
        multimap();
        void put(string, V);
        bool find(string, V*);
        int numberOfNodesAtKey(string);
        int numberOfNodesAtIndex(int);
        void remove(string, V&);
};


#endif // MULTIMAP_H_INCLUDED

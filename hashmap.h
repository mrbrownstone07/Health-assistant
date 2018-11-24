#pragma once
#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED
#include <string>
using namespace std;

template <class V>
class hashmap{

    private:
        struct hashNode{
            string key;
            V value;
            hashNode(string key, V value) : key(key), value(value){}
            hashNode(){
                key = "\0";
            }
        };

        int tableSize;
        hashNode **hashTable;
        int primaryHashCode(string);
        int secondaryHashCode(string);

    public:
        hashmap();
        void put(string, V);
        bool find(string, V&);
        void remove(string, V&);
};

#endif // HASHMAP_H_INCLUDED

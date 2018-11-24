#include "multimap.h"
#include <iostream>
template<class V>
multimap<V>::multimap(){
    tableSize = 1000007;
    hashTable = new mapNode * [tableSize];

/*     for(int i = 0; i<tableSize; i++){
        hashTable[i] = NULL;
    } */
}

template<class V>
int multimap<V>::primaryHashCode(string key){
    int h = 0;

    for(int i = 0; i<key.length(); i++)
        h = 31*h + key[i];

    h %= 1000007;
    //cout << "Multimap : " << h << endl;
    return h *= (h < 0) ? -1 : 1;
}

template <class V>
void multimap<V>::put(string key, V value){
    mapNode *newItem = new mapNode;
    newItem->key = key;
    newItem->value = value;
    newItem->next = NULL;

    int index = primaryHashCode(key);

    if(hashTable[index] != NULL){
        mapNode* ptr = hashTable[index];

        while(ptr->next)
            ptr = ptr->next;
        ptr->next = newItem;

    }

    else hashTable[index] = newItem;
}

template <class V>
bool multimap<V>::find(string key, V* outputArr){
    int index = primaryHashCode(key);
    mapNode* ptr = hashTable[index];
    int count = 0;

    while(ptr){
        if(ptr->key == key){
            outputArr[count] = ptr->value;
            count++;
        }
        ptr = ptr->next;
    }

    return (count > 0) ? true : false;
}

template <class V>
int multimap<V>::numberOfNodesAtKey(string key){
    int index = primaryHashCode(key);
    mapNode* ptr = hashTable[index];
    int count = 0;

    while(ptr){
        if(ptr->key == key){
            count++;
        }
        ptr = ptr->next;
    }

    return count;
}

template <class V>
void multimap<V>::remove(string k, V& value){
    int index = primaryHashCode(k);
    mapNode* prev = NULL;
    mapNode* curr = hashTable[index];

    while((curr->value != value)){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        std::cout << "Not Found!" << endl;
    }
    else{
        if(prev == NULL){
            hashTable[index] = curr->next;
        }else{
            prev->next = curr->next;
        }
        delete curr;
    }
}


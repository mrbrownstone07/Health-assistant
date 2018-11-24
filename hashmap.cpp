#include "hashmap.h"

template<class V>
hashmap<V>::hashmap(){
    tableSize = 1000007;
    hashTable = new hashNode * [tableSize];

/*     for(int i = 0; i<tableSize; i++){
        hashTable[i] = NULL;
    } */
}

template<class V>
int hashmap<V>::primaryHashCode(string key){
    int h = 0;
    int base [] = {31,37,41,43,47,53,59,61,67,71,73};
    int bIndex = 0;

    for(int i = 0; i<key.length(); i++){
        h = base[bIndex++]*h + key[i];
        if(bIndex > 10) bIndex = 0;
    }

    h %= 1000007;
    return h *= (h < 0) ? -1 : 1;
}

template<class V>
int hashmap<V>::secondaryHashCode(string key){
    int h = 0;

    for(int i = 0; i<key.length(); i++){
        h = 37*h + key[i];
    }

    h %= 1000007;
    return h *= (h < 0) ? -1 : 1;
}

template<class V>
void hashmap<V>::put(string key, V value){
    hashNode *newItem = new hashNode;
    newItem->key = key;
    newItem->value = value;

    int index = primaryHashCode(key);

    if(hashTable[index] != NULL){
        index = secondaryHashCode(key);
    }

    hashTable[index] = newItem;
    //cout << "HashCode: " << index << endl;
}

template<class V>
bool hashmap<V>::find(string key, V& value){
    int index = primaryHashCode(key);

    if(hashTable[index] != NULL && hashTable[index]->key == key){
        value = hashTable[index]->value;
        return true;
    }
    else{
        index = secondaryHashCode(key);
        if(hashTable[index] != NULL && hashTable[index]->key == key){
            value = hashTable[index]->value;
            return true;
        }
        else{
            return false;
        }
    }
}

template <class V>
void hashmap<V>::remove(string key, V& id){
    int index = primaryHashCode(key);

    if(hashTable[index]->key == key){
       id = hashTable[index]->value;
       hashTable[index] = NULL;
    }else{
        index = secondaryHashCode(key);
        if(hashTable[index]->key == key){
            id = hashTable[index]->value;
            hashTable[index] = NULL;
        }
    }
}



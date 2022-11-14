
#ifndef DATASTRUCTURE_EX2_HASHTABLE_H
#define DATASTRUCTURE_EX2_HASHTABLE_H
using namespace std;
#include <iostream>
#include <string>
#include "Item.h"
#include <cmath>

template <class T,class K>
class HashTable
{
protected:
    int size;
    Item<T,K>* arr;
    bool prime(int n);
    int hash(K key, int i);
    virtual int h1(K key)=0;
    virtual int h2(K key)=0;
public:
    HashTable(int m=10);
    ~HashTable();
    void add(K& key, T& dat);
    void remove(K key);
    int search(K key);
    T* entryData(K i);
    void print();
};

template<class T, class K>
bool HashTable<T, K>::prime(int n) {

    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}

template<class T, class K>
T *HashTable<T, K>::entryData(K i) {
    int ind = search(i);
    if (ind == -1)
        return NULL;
    else
        return &(arr[ind].data);
}

template<class T, class K>
HashTable<T, K>::HashTable(int m) {
    while (!prime(m)) m++;
    arr = new Item<T,K>[m];
    size = m;
}

template<class T, class K>
HashTable<T, K>::~HashTable() {
    delete arr;
}

template<class T, class K>
int HashTable<T, K>::hash(K key, int i) {
    return (h1(key) + i*h2(key)) % size;
}

template<class T, class K>
void HashTable<T, K>::add(K &key, T &dat) {
    int i = search(key);
    if(i == -1){
        for(i = 0; i < size; i++)
        {
            int j = hash(key,i);
            if(!(arr[j].flag == full)) {
                arr[j].data = dat;
                arr[j].key = key;
                arr[j].flag = full;
                return;
            }
        }


    }
}

template<class T, class K>
int HashTable<T, K>::search(K key) {
    for(int i = 0; i < size; i++)
    {
        int j = hash(key,i);
        if(arr[j].flag == full && arr[j].key == key)
            return i;
    }
    return -1;
}

template<class T, class K>
void HashTable<T, K>::remove(K key) {
    int i = search(key);
    if(i != -1) arr[i].flag = deleted;
}

template<class T, class K>
void HashTable<T, K>::print() {
    cout<<size<<endl;
    for(int i = 0; i < size; i++)
    {
        if(arr[i].flag == full)
            cout<<i<<":"<<arr[i].data<<" ";
    }
    cout<<endl;
}


#endif

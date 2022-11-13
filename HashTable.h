
#ifndef DATASTRUCTURE_EX2_HASHTABLE_H
#define DATASTRUCTURE_EX2_HASHTABLE_H
#include <iostream>
#include <string>
using namespace std;
#include "Item.h"


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
    int remove(K key);
    int search(K key);
    T* entryData(K i)
    {
        int ind = search(i);
        if (ind == -1)
            return NULL;
        else
            return &(arr[ind].data);
    }
    void print();
};


#endif

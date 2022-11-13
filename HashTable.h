
#ifndef DATASTRUCTURE_EX2_HASHTABLE_H
#define DATASTRUCTURE_EX2_HASHTABLE_H


#include <iostream>
#include <string>
using namespace std;

template <class T,class K>
class HashTable
{
protected:

    enum state {empty, full, deleted};
    template <class T,class K>
    class Item
    {
    public:
        T data;
        K key;
        state flag;
        Item(){}
        Item(T d, K k, state f){ data=d; key=k; flag=f;}
    };


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

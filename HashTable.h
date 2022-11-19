/*
class hashtable A generic class defines object kind item
 */
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
    bool prime(int n);//return true if the number is prime
    int hash(K key, int i);//get key and number i and return the position the key is in the table
    //two virtual hash function
    virtual int h1(K key)=0;
    virtual int h2(K key)=0;
public:
    HashTable(int m=10);//constructor
    ~HashTable();//destructor
    void add(K& key, T& dat);//add key and date to the table
    void remove(K key);//removing key from the table
    int search(K key);//search a key in the table by using hash function
    void print();//print all the subject in the table
};
//The function return true if the number is prime
template<class T, class K>
bool HashTable<T, K>::prime(int n) {

    for(int i = 2; i <= sqrt(n); i++)//run from 2 until the sqrt of the number and check if the number is divided in i
        if(n % i == 0) return false;
    return true;//if the number is prime
}
//get a number and defines arr in size of this number and checking if the number is prime
template<class T, class K>
HashTable<T, K>::HashTable(int m) {
    while (!prime(m)) m++;//if the number not prime
    arr = new Item<T,K>[m];
    size = m;
}
//destructor
template<class T, class K>
HashTable<T, K>::~HashTable() {
    delete[] arr;
}
//return the position that the key is in the table
template<class T, class K>
int HashTable<T, K>::hash(K key, int i) {
    return (h1(key) + i*h2(key)) % size;
}
//add new key and data to the table
template<class T, class K>
void HashTable<T, K>::add(K &key, T &dat) {
    int i = search(key);//get the position the key needs to be
    if(i == -1)//if the key not find
    {
        for(i = 0; i < size; i++)//look for a place to put the key in the table
        {
            int j = hash(key,i);//get the new position
            if(!(arr[j].flag == full))//check if the position is not full
            {
                //puts the values in the table
                arr[j].data = dat;
                arr[j].key = key;
                arr[j].flag = full;
                return;
            }
        }
    }else//if the key find
    {
        arr[i].data = dat;
    }
}
//search key by using hash table
template<class T, class K>
int HashTable<T, K>::search(K key) {
    for(int i = 0; i < size; i++)
    {
        int j = hash(key,i);
        if(arr[j].flag == full && arr[j].key == key)
            return j;
    }
    return -1;
}
//removing key from the table
template<class T, class K>
void HashTable<T, K>::remove(K key) {
    int i = search(key);//get the position
    if(i != -1) arr[i].flag = deleted;//deleted from the table
}
//print all the subject
template<class T, class K>
void HashTable<T, K>::print() {
    for(int i = 0; i < size; i++)
    {
        if(arr[i].flag == full)//check if the position is full and print it
            cout<<i<<":"<<arr[i].data<<" ";
    }
    cout<<endl;
}


#endif

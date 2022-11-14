//
// Created by Yoni on 14/11/2022.
//

#include "HashInt.h"

int hashInt(int key, int size){
    return key % size;
}

int HashInt::h1(int key) {
    return hashInt(key, size);
}

int HashInt::h2(int key) {
    return 1;
}

HashInt::HashInt(int i) : HashTable(i){

}



//
// Created by Yoni on 14/11/2022.
//

#ifndef DATASTRUCTURE_EX2_HASHINT_H
#define DATASTRUCTURE_EX2_HASHINT_H
#include "HashTable.h"

class HashInt : public HashTable<int,int>{
protected:
    int h1(int key) override;

    int h2(int key) override;

public:
    HashInt(int i);

};


#endif //DATASTRUCTURE_EX2_HASHINT_H

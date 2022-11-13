//
// Created by 97253 on 13/11/2022.
//

#ifndef DATASTRUCTURE_EX2_ITEM_H
#define DATASTRUCTURE_EX2_ITEM_H

enum state {empty, full, deleted};
template <class T,class K>
class Item {
public:
    T data;
    K key;
    state flag;
    Item(){}
    Item(T d, K k, state f){ data=d; key=k; flag=f;}
};


#endif

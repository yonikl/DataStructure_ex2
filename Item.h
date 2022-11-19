/*
 class Item a generic class defines two objects
 */

#ifndef DATASTRUCTURE_EX2_ITEM_H
#define DATASTRUCTURE_EX2_ITEM_H

enum state {empty, full, deleted};
template <class T,class K>
class Item {
public:
    T data;
    K key;
    state flag;//enum
    Item(){}//empty constructor
    Item(T d, K k, state f){ data=d; key=k; flag=f;}//constructor

    //operators
    bool operator==(const Item &rhs) const {
        return key == rhs.key;
    }

    bool operator!=(const Item &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Item &rhs) const {
        return key < rhs.key;
    }

    bool operator>(const Item &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Item &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Item &rhs) const {
        return !(*this < rhs);
    }
};


#endif

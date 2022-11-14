
#include "HSubject.h"

void HSubject::printS(string ky) {
    for(int i = 0;i < size; i++){
        if(arr[i].flag == full && arr[i].key == ky){
            cout << "Subject "  << arr[i].key << " " << arr[i].data.size() << " topics:" << endl;
            for(auto t : arr[i].data) cout << t << " ";
            cout << endl;
            return;
        }
    }
}

void HSubject::printN(string ky, int N) {
    for(int i = 0;i < size; i++){
        if(arr[i].flag == full && arr[i].key == ky){
            cout << "Subject "  << arr[i].key << " " << arr[i].data.size() << " topics:" << endl;
            int j = 0;
            for(auto t : arr[i].data){
                if(j >= N) break;
                cout << t << " ";
                j++;
            }
            cout << endl;
            return;
        }
    }
}

void HSubject::print() {
    list<Item<list<string>,string>> newList;
    for(int i = 0;i < size; i++) {
        if(arr[i].flag == full) newList.push_front(arr[i]);
    }
    newList.sort();
    for(auto t : newList){

    }


}

void HSubject::startNewTable() {
    for(int i = 0;i < size; i++) arr[i].flag = empty;
}

void HSubject::addSubjectAndTitle(string s, string t) {
    for(int i = 0;i < size; i++){
        if(arr[i].key == s){
            arr[i].data.push_front(t);
            return;
        }
    }
    this->add(s, *(new list<string>));
    this->addSubjectAndTitle(s, t);
}

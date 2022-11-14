
#include "HSubject.h"

void HSubject::printS(string ky) {
    int i = search(ky);
    if(i != -1){
        cout << "Subject "  << arr[i].key << " " << arr[i].data.size() << " topics:" << endl;
        for(const auto& t : arr[i].data) cout << t << " ";
        cout << endl;
        return;
    } else {
        cout << "ERROR" <<endl;
    }
}

void HSubject::printN(string ky, int N) {
    int i = search(ky);

    if(i != -1){
        int j = 0;
        for(const auto& t : arr[i].data){
            if(j >= N) break;
            cout << t << " ";
            j++;
        }
        cout << endl;
        return;
    }else{
        cout << "ERROR" << endl;
    }

}

void HSubject::print() {
    list<Item<list<string>,string>> newList;
    for(int i = 0;i < size; i++) {
        if(arr[i].flag == full) newList.push_front(arr[i]);
    }
    newList.sort();
    cout << "All subjects and titles:" << endl;
    for(const auto& t : newList){
        cout << t.key << ": ";
        for (auto r : t.data) {
            cout << r << " ";
        }
        cout << endl;
    }


}

void HSubject::startNewTable() {
    for(int i = 0;i < size; i++) arr[i].flag = empty;
}

void HSubject::addSubjectAndTitle(string s, string t) {
    int i = search(s);
    if(i != -1){
        arr[i].data.push_front(t);
        return;
    }
    list<string> newList;
    newList.push_front(t);
    this->add(s, newList);
}

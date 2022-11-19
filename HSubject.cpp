/*
implement file for  HSubject
 */
#include "HSubject.h"

//The function get a subject and print all the topics in this subject
void HSubject::printS(string ky) {
    int i = search(ky);//get the position
    if(i != -1){//if the key found
        cout << "Subject "  << arr[i].key << " " << arr[i].data.size() << " topics:" << endl;//print the subject
        for(const auto& t : arr[i].data) cout << t << " ";//print all the topics
        cout << endl;
        return;
    } else {//if the kee not found in the table
        cout << "ERROR" <<endl;
    }
}
//The function get a subject and number of topics to print
void HSubject::printN(string ky, int N) {
    int i = search(ky);//get the position
    if(i != -1){//if the key found
        int j = 0;//print until j equal to N
        for(const auto& t : arr[i].data){
            if(j >= N) break;
            cout << t << " ";
            j++;
        }
        cout << endl;
        return;
    }else cout << "ERROR" << endl;//if the kee not found in the table

}
//print all the subject alphabetically and title in the table
void HSubject::print() {
    list<Item<list<string>,string>> newList;
    for(int i = 0;i < size; i++) {//move all the subject to the new list
        if(arr[i].flag == full) newList.push_front(arr[i]);
    }
    newList.sort();//sort rhe list
    cout << "All subjects and titles:" << endl;
    for(const auto& t : newList){//print all the subject's
        cout << t.key << ": ";
        for (auto r : t.data) {
            cout << r << " ";
        }
        cout << endl;
    }


}
//start new table and put's empty in the flag in every position
void HSubject::startNewTable() {
    for(int i = 0;i < size; i++) arr[i].flag = empty;
}
//get a subject and title and puts them in the table
void HSubject::addSubjectAndTitle(string s, string t) {
    int i = search(s);//get the position
    if(i != -1){
        arr[i].data.push_front(t);//push to the front in the list
        return;
    }
    //if the subject didn't fond
    list<string> newList;//create new list
    newList.push_front(t);//push to the list the topic
    this->add(s, newList);//sand to add function to add the subject to the table
}

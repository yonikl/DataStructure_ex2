/*
class HSubject heir from class HashTable and def list of string and subject string
 */
#ifndef DATASTRUCTURE_EX2_HSUBJECT_H
#define DATASTRUCTURE_EX2_HSUBJECT_H

#include <string>
#include <list>
#include "HashTable.h"

const int MAX = 1000;

class HSubject :public HashTable<list<string>,string>
{
private:

    int key(string s) { return (int)s[0] + (int)s[1] + (int)s[s.length() - 1]; }//return the position the string should be

public:
    HSubject(int n = MAX) :HashTable  (n) {}//send to HashTable constructor
    int h1(string s) { return key(s) % size; }//hash function return the position
    int h2(string s) { return (key(s) % (size - 1) + 1) % size; }//skip function
    void printS(string ky);//get a subject and print all the topics in this subject
    void printN(string ky, int N);//get a subject and number of topics to print
    void print();//print all the subject's and the topics in the table
    void startNewTable();//Initializes the table
    void addSubjectAndTitle(string s, string t);//get a subject and title and puts them in the table


};


#endif

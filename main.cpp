/*
Name: Raz Leibovitch
 Id:209521863
 Name: Yonatan Klein
 Id: 322961764
 */
using namespace std;
#include <iostream>
#include "HSubject.h"

int main()
{
    char ch;
    int n;
    HSubject hs(1000);
    string subject, title;

    cout << "Hash Table\n";
    cout << "\nChoose one of the following" << endl;
    cout << "n: New hash table" << endl;
    cout << "a: Add a subject and a title" << endl;
    cout << "d: Del a subject " << endl;
    cout << "t: print all titles of the subject " << endl;
    cout << "s: print N first appearances of a subect " << endl;
    cout << "p: print all non-empty entries " << endl;
    cout << "e: Exit" << endl;
    do
    {
        cin >> ch;
        switch (ch)
        {

            case 'n':hs.startNewTable(); break;
            case 'a':cout << "Enter a subject and a title\n";
                cin >> subject >> title;
                hs.addSubjectAndTitle(subject, title);
                break;
            case 'd':cout << "Enter a subject to remove\n";
                cin >> subject;
                hs.remove(subject); break;
            case 't':cout << "enter subject to print\n";
                cin >> subject;
                hs.printS(subject); break;
            case 's':cout << "enter a subject and N\n"; cin >> subject >> n;
                hs.printN(subject, n); break;
            case 'e':cout << "bye\n"; break;
            case 'p':hs.print(); break;
            default: cout << "ERROR\n";  break;
        }
    } while (ch != 'e');
    return 0;
}
/*
Hash Table

Choose one of the following
n: New hash table
a: Add a subject and a title
d: Del a subject
t: print all titles of the subject
s: print N first appearances of a subect
p: print all non-empty entries
e: Exit
n
a
Enter a subject and a title
subject1 title1
a
Enter a subject and a title
subject1 title2
a
Enter a subject and a title
subject1 title3
a
Enter a subject and a title
subject2 title2
a
Enter a subject and a title
subject1 title4
t
enter subject to print
subject2
Subject subject2 1 topics:
title2
s
enter a subject and N
subject2 3
title2
p
All subjects and titles:
subject1: title4 title3 title2 title1
subject2: title2
d
Enter a subject to remove
subject1
p
All subjects and titles:
subject2: title2
d
Enter a subject to remove
subject3
t
enter subject to print
subject3
ERROR
e
bye
 */
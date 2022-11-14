using namespace std;
#include <iostream>
#include "HSubject.h"
#include "HashInt.h"

int main()
{
//    HashInt hash(12);
//    int arr[20] = {12,34,25,45,75,24,86,45,79,67,23,64,135,643,234,647,246,242,75,96};
//    for(int i = 0; i <=9; i++ ) {
//        hash.add(arr[2*i], arr[2*i+1]);
//        hash.print();
//    }
//    hash.print();

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
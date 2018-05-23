#include <iostream>
#include "ValSet.hpp"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    ValSet<char> mySet;
    mySet.add('a');
    mySet.add('b');
    mySet.add('c');
    mySet.remove('c');
    
    int size = mySet.size();
    cout << "size of mySet = " << size << endl;
    cout << "size of Array = " << mySet.getArraySize() << endl;
    cout << "Conatin c: " << mySet.contains('c') << endl;

    
    ValSet<char> mySet2 = mySet;
    int size2 = mySet.size();
    cout << "size of mySet2 = " << size2 << endl;

    mySet.printSet();
    cout << "\n" << endl;

    mySet2.add('x');
    mySet2.add('y');
    mySet2.add('z');

    mySet2.printSet();
    cout << "\n" << endl;

    ValSet<char> mySet3 = mySet * mySet2;
    mySet3.printSet();


    mySet.add('q');
    ValSet<char> mySet4 = mySet + mySet2;
    mySet4.printSet();

    // bool check2 = mySet2.contains('j');
    // //cout << "check2: " << check2 << endl;
    // ValSet<char> myUnion = mySet *  mySet2;
    // cout << "magic time: ";
    // myUnion.printSet();
    // //cout << "\n\n" <<  mySet + mySet2 << endl<<endl;
}
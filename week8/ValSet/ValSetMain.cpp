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
    
    ValSet<char> mySet2 = mySet;

    mySet2.add('x');
    mySet2.add('y');
    mySet2.add('z');
    mySet.add('q');

    
    ValSet<char> myUnion = mySet + mySet2;
    cout << "myUnion: = a, b, x, y, z, q" << endl;
    cout << "myUnion size: " << myUnion.size() << endl;
    cout << "Contain a: " << myUnion.contains('a') << endl;
    myUnion.printSet();
    cout << "\n" << endl;

    ValSet<char> mySet3;
    mySet3.add('a');
    mySet3.add('b');
    
    ValSet<char> mySet4 = mySet3;

    mySet4.add('x');
    mySet4.add('y');
    mySet4.add('z');
    mySet3.add('z');
    mySet3.remove('a');

    ValSet<char> myIntersection = mySet3 * mySet4;
    cout << "myUmyIntersectionnion: = a, b, z" << endl;
    cout << "myIntersection size: " << myIntersection.size() << endl;
    cout << "Contain a: " << myIntersection.contains('a') << endl;
    myIntersection.printSet();
    cout << "\n" << endl;



    // bool check2 = mySet2.contains('j');
    // //cout << "check2: " << check2 << endl;
    // ValSet<char> myUnion = mySet *  mySet2;
    // cout << "magic time: ";
    // myUnion.printSet();
    // //cout << "\n\n" <<  mySet + mySet2 << endl<<endl;
}
#include <iostream>
#include <vector>
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
    cout << "myIntersection: = b, z" << endl;
    cout << "myIntersection size: " << myIntersection.size() << endl;
    cout << "Contain a: " << myIntersection.contains('a') << endl;
    myIntersection.printSet();
    cout << "\n" << endl;

    
    ValSet<char> mySet5;
    mySet5.add('a');
    mySet5.add('b');
    
    ValSet<char> mySet6 = mySet5;

    mySet6.add('y');
    mySet6.add('z');
    mySet5.add('z');

    ValSet<char> mySymmetric = mySet5 / mySet6;
    cout << "mySymmetric: = y" << endl;
    cout << "mySymmetric size: " << mySymmetric.size() << endl;
    cout << "Contain a: " << mySymmetric.contains('a') << endl;
    mySymmetric.printSet();
    cout << "\n" << endl;


    ValSet<int> setInteger;
    setInteger.add(1);
    setInteger.add(2);
    // cout << setInteger.isEmpty() << endl;
    // cout << setInteger.contains(1) << endl;
    // cout << setInteger.size() << endl;
    std::vector<int> v = setInteger.getAsVector();
    for(int i = 0; i < v.size() ; i++) {
        cout << v.at(i) << " ";
    }
    cout << "\n" << endl;
    // setInteger.remove(3);
    // setInteger.remove(2);

    // ValSet<int> setCopy = setInteger;
    // cout << setCopy.size() << endl;

    // setInteger.remove(1);

    // cout << setInteger.isEmpty() << endl;

    // bool check2 = mySet2.contains('j');
    // //cout << "check2: " << check2 << endl;
    // ValSet<char> myUnion = mySet *  mySet2;
    // cout << "magic time: ";
    // myUnion.printSet();
    // //cout << "\n\n" <<  mySet + mySet2 << endl<<endl;
}
#include <iostream>
#include <iomanip>
using namespace std;

// Template definition for square function
template <class T>
T square(T number) {
  return number * number;
}

int main() {

  cout << "Enter an INTEGER\n";
  int iValue;
  cin >> iValue;


  cout << "The square is: " << square(iValue) << endl;

  cout << "Enter a Double\n";
  double dValue;
  cin >> dValue;

  cout << "The square is: " << square(dValue) << endl;

  return 0;
}
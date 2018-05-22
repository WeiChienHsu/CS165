#include <iostream>
#include <string>
#include <algorithm> // Needed for swap

using namespace std;

template<class T>
void swapAB(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  double a = 1.0, b = 2.0;
  swapAB(a, b);
  cout << "a: " << a << "b: " << b << endl;
  swap(a, b);
  cout << "a: " << a << "b: " << b << endl;
  
  string s = "Hey", p = "I just Met you!";
  swapAB(s, p);
  cout << s  << " " << p << endl;

  return 0;
}
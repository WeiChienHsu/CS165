#include <iostream>
using namespace std;

template <class T>
T sum(T a1, T a2) {
  return a1 + a2;
}

template <class T>
T sum(T a1, T a2, T a3) {
  return a1 + a2 + a3;
}

int main() {
  cout << "1 + 2 = " << sum(1, 2) << endl;
  cout << "2 + 4 + 6 = " << sum(2,4,6) << endl;
  return 0;
}
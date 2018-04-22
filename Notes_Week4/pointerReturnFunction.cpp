#include <iostream>
using namespace std;

int Add(int a, int b) {
  return a + b;
}

int main() {
  int c;
  int (*p)(int, int);
  p = Add;
  c = p(4,5);
  cout << c << endl;

  return 0;
}
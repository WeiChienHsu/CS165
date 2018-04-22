#include <iostream>
using namespace std;

void A() {
  cout << "Call Back Function was called!" << endl;
}

void B(void (*ptr)()) {
  ptr();
}

int main() {
  B(A);
  return 0;
}
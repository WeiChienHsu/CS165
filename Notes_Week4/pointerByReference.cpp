#include <iostream>
using namespace std;

int *Add(int *a, int *b) {
  int *c = new int; // New a space in Heap
  *c = *a + *b; // Value in the C will be the sum of Value of Address a and b
  cout << "Address of c in Heap:(Add function) " << c << endl; // 0x7fc083c02810

  return c;
}

int main() {
  int a = 4, b = 6;
  int *ptr = Add(&a, &b); // Pointer points to the C stored in the Heap memory 
  cout << "Address of pointer which save the address of C in Heap" << &ptr << endl; // 0x7ffeee3148f8
  cout << "Address of C in Heap (Main Function)" << ptr << endl; // 0x7fde26402810
  cout << *ptr << endl;
  return 0;
}
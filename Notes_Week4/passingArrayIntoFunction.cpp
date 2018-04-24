#include <iostream>
using namespace std;


// Passing a pointer or Passing an Array of Integer
void passing(int *arr , int size) {
  for(int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }
}

int *creating() {
  return new int[3];
}

void creating(int **a, int size) {
  *a = new int[size]; // Dereference the address of Pointer and points to Integer Array
}

int main() {
  int sarr[3], *darr;
  // darr = creating();
  creating(&darr, 3); // Pass the address of Pointer

  passing(sarr, 3);
  passing(darr, 3);

  for(int i = 0; i < 3; i++) {
    cout << "Dynamic Array: " << darr[i] << endl;
    cout << "Dynamic Address: " << &darr[i] << endl;
    cout << "Dynimaic Pointer Address: " << &darr << endl;
    cout << "Dynimaic Pointer points to: " << darr + i << endl;
  }

  delete[] darr;
  return 0;
}
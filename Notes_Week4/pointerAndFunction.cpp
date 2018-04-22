#include <iostream>
using namespace std;
int SumOfElements(int *A, int size) {
  int i, sum = 0;
  cout << "Size of A[] in sum function: " << sizeof(A) << endl;
  for(i = 0; i < size; i++) {
    sum += A[i];
  }
  
  cout << "Size of A[0] in sum function: " << sizeof(A[0]) << endl;
  return sum;
}

int main() {
  int A[] = {1,2,3,4,5};
  int size = sizeof(A) / sizeof(A[0]);
  cout << "Size of A[] in main function: " << sizeof(A) << endl;
  cout << "Size of A[0] in main function: " << sizeof(A[0]) << endl;
  cout << "Sum of the Array: " << SumOfElements(&A[0], size) << endl;
  cout << "Sum of the Array: " << SumOfElements(A, size) << endl;

  return 0;
}
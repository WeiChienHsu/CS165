#include <iostream>
using namespace std;

int main() {
  int** ptrToPtr = new int*[5]; 
  // Pointer in Stack : Points to the "Integer Pointers" which points to Inter Array in Heap
  for(int i = 0; i < 5; i++) 
    *(ptrToPtr + i) = new int[5];
    // ptrToPtr[i] = new int[5];
     
    // Point to the Array of Integer in different address in Heap
  

  for(int i = 0; i < 5; i++) {
    delete[] ptrToPtr[i];
  }
  delete[] ptrToPtr;

  return 0;

}
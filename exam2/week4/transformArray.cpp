#include <iostream>

// The pointer is passed by reference because you want to change the value of the pointer.

void transformArray(int* &mainArray, int size){
  int *tempArray = new int[size*2];

  for(int i = 0; i < size; i++) {
    tempArray[i] = mainArray[i];
  }

  delete []mainArray;

  for(int i = size; i < 2 * size; i++) {
    tempArray[i] = tempArray[i - size] * 2;
  }

  // In this step, we chagne the pointer mainArray to the tempArray
  mainArray = tempArray; 
}

int main() {
  int* myArray = new int[3];
  myArray[0] = 4;
  myArray[1] = 2;
  myArray[2] = 5;

  transformArray(myArray, 3);

  for(int i = 0; i < 6; i++) {
    std::cout << myArray[i] << std::endl;
  }

  delete []myArray;
}
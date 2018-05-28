#include <iostream>

int arrayMax(int *arr, int size) {
  if(size == 1) return arr[0];
  int currentMax = arr[size - 1];
  int nextNumber = arrayMax(arr, size - 1);
  if(currentMax > nextNumber) {
    return currentMax;
  } else {
    return nextNumber;
  }
}

int main() {
  int arr[5] = {1, 2, 8, 4, 0};
  std::cout << arrayMax(arr, 5) << std::endl; 
}
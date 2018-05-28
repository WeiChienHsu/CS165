#include <iostream>

bool isDecreasing(int *arr, int size) {
  if(size == 1) return true;

  if(arr[size - 1] < arr[size - 2]) {
    return true && isDecreasing(arr, size - 1);
  } else {
    return false;
  }
}

int main() {
  int arrTrue[4] = {4,3,2,1};
  int arrFalse[4] = {4,4,1,2};
  std::cout << isDecreasing(arrTrue, 4) << std::endl;
  std::cout << isDecreasing(arrFalse, 4) << std::endl;
}
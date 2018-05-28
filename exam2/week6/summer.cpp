#include <iostream>

int summer(int *arr, int size) {
  if(size == 1) return arr[0];
  return arr[size - 1] + summer(arr, size - 1);
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int size = 5;
  std::cout << summer(arr, size)  << std::endl; 
}
#include <iostream>

void displayArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}

void displayPassByReference(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    std::cout << *(arr++)* 2 << std::endl;
  }
}


int main() {
  int arr[] = {1,2,3,4};
  const int SIZE = 4;
  displayArray(arr, SIZE);
  displayPassByReference(arr, SIZE);
  return 0;
}
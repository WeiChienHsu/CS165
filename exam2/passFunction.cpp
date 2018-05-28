#include <iostream>

int compare(int a, int b) {
  if(a > b) return -1;
  else return 1;
}

void bubbleSort(int *arr, int size, int (*compare)(int, int)) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1; j++) {
      if(compare(arr[j], arr[j+1]) > 0) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
 const int SIZE = 5;
 int arr[SIZE] = {1, 5, 3, 4, 2};
 bubbleSort(arr, SIZE, compare);
 for(int i = 0; i <SIZE; i++) {
   std::cout << arr[i] << std::endl;
 }
 return 0;
}
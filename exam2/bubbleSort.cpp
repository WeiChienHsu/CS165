#include <iostream>

void bubbleSort(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void selectionSort(int *arr, int size) {
  int minIndex = 0;
  int minValue = arr[0];
  for(int i = 0; i < size - 1; i++) {
    minIndex = i;
    minValue = arr[i];
    for(int j = i + 1; j < size; j++) {
      if(minValue > arr[j]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

int main() {
  int arr[] = {1, 2, 10, 4, 12};
  int size = 5;
  selectionSort(arr, size);
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}
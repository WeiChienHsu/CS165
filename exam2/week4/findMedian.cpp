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

double findMedian(int *arr, int size) {
  bubbleSort(arr, size);
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  if(size % 2 != 0) {
    return arr[(size / 2)];
  } else {
    int mid = size / 2;
    return (arr[mid] + arr[mid - 1]) / 2.0;
  }
}

int main() {
  int arr[5]  = {1, 6, 7, 3 ,2};
  int arr2[4] = {1, 4, 2, 3}; 
  std::cout << findMedian(arr, 5) << std::endl;
  std::cout << findMedian(arr, 4) << std::endl;
  return 0;
}
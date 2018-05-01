/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  1. bubbleSort(): We need to keep the last number the largest, 
                    start from the first to the currnt Last, if arr[j-1] > arr[j],
                    we swap these two numbers.
                    
                 2. swap(): Switch the current number by index with the minIndex.   
*********************************************************************/
#include <iostream>

void swap(int *arr, int i, int j);

void bubbleSort(int *arr, int size) {
  for(int curLargeIndex = size - 1; curLargeIndex >= 0; curLargeIndex--) {
    // int curLarge = arr[curLargeIndex];
    for(int j = 0; j < curLargeIndex; j++) {
      if(arr[j] > arr[j + 1]) {
        swap(arr, j, j+ 1);
      }
    }
  }
}

void bubbleSort2(int arr[], int size) {
  int count;
  bool madeAswap = false;
  do {
    for(count = 0; count < size - 1; count++) {
      madeAswap = false;
      if(arr[count] > arr[count+1]) {
        swap(arr, count, count + 1);
        madeAswap = true;
      }
    }
  } while (madeAswap);
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main() {
  int arr[] = {1, 3, 5, 4};
  bubbleSort2(arr, 4);
  for(int i = 0; i < 4; i++) 
    std::cout << arr[i] << std::endl;
  
  return 0;
}
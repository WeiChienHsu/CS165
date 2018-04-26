/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  1. SelectSort(): Take the Whole array and Size as parameters 
                    and Search through all indexs in the array
                 2. FindTheMinIndex(): to find if there is a smaller number 
                    in the rest of the array, return the minIndex.
                 3. swap(): Switch the current number by index with the minIndex.   
*********************************************************************/
#include <iostream>


void swap(int* arr, int i, int j);
int findMinIndex(int arr[], int size, int curInedx);

void selectSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    // Based on current index and search the rest of array
    int minIndex = findMinIndex(arr, size, i);
    swap(arr, i, minIndex);
  }
}

int findMinIndex(int arr[], int size, int curInedx) {
  int minIndex = curInedx;
  for(int i = curInedx + 1; i < size; i++) {
    if(arr[i] < arr[curInedx]) {
      minIndex = i;
    }
  }
  return minIndex;
}

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main() {
  int arr[] = {1, 3, 5, 4};
  selectSort(arr, 4);
  for(int i = 0; i < 4; i++) 
    std::cout << arr[i] << std::endl;
  
  return 0;
}
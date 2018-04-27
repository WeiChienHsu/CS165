/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  1. InsertionSort(): Assume the first number is inordered, 
                    go through the rest of the array. If there is a number 
                    smaller then the previous one, move all the numbers
                    move forward till we find the insert point.  
*********************************************************************/
#include <iostream>

void insertionSort(int *arr, int size) {
  for(int i = 1; i < size ; i++) {
    int next = arr[i];
    int currentIndex = i;
    while(currentIndex > 0 && next < arr[currentIndex - 1]) {
      arr[currentIndex] = arr[currentIndex - 1];
      currentIndex--;
    }
    arr[currentIndex] = next;
  }
}

int main() {
  int arr[] = {1, 4, 3, 2};
  insertionSort(arr, 4);

  for(int i = 0; i < 4; i++)
    std::cout << arr[i] << std::endl;
  
  return 0;
}
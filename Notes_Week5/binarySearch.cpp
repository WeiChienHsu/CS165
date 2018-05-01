#include <iostream>




int binarySearch(int arr[], int size, int target) {
  int start = 0, end = size - 1;
  while(start + 1 < end) {
    int middle = start + (end - start) / 2;
    if(target == arr[middle]) {
        start = middle;
    } else if(target > arr[middle]) {
        start = middle;
    } else {
        end = middle;
    }
  }

  if(arr[start] == target) return start;
  if(arr[end] == target) return end;

  return -1;
}

int main() {
  int arr[5] = {1,2,5,8,10};
  std::cout << binarySearch(arr, 5, 11)<< std::endl; 

  return 0;
}
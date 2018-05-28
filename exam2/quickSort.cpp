#include <iostream>

void swap(int a, int b, int* arr) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

int partition(int *arr, int start, int end) {
  int pivot = arr[end];
  int boundry = start;
  for(int i = start; i < end; i++) {
    if(arr[i] < pivot) {
      swap(i, boundry, arr);
      boundry++;
    }
  }
  swap(end, boundry, arr);
  return boundry;
}

void quickSort(int *arr, int start, int end) {
  if(start >= end) return;
  int p = partition(arr, start, end);
  quickSort(arr, start, p - 1);
  quickSort(arr, p + 1, end);
  return;
}

int main() {
  int arr[9] = {1, 10, 8, 3, 2, 9, 4, 0, 11};
  quickSort(arr, 0, 8);
  for(int i = 0; i < 9; i++) {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}
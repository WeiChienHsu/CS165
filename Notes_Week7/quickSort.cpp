#include <iostream>
using namespace std;

int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void swap(int arr[], int j, int k);

int partition(int arr[], int start, int end){
  int pivotValue = arr[end];
  int pivotB = start; // B for Boundry

  for(int pos = start; pos < end; pos ++) {
    if(arr[pos] < pivotValue) {
      swap(arr, pos, pivotB);
      pivotB++;
    }
  }

  swap(arr, end, pivotB);
  return pivotB;
}


void quickSort(int arr[], int start, int end) {
  if(start < end) {
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
  }
}

void swap(int arr[], int i, int j) {
  int temp = arr[j];
  arr[j] = arr[i];
  arr[i] = temp;
}

int main() {
  int arr[] = {10, 5, 3, 21, 33, 100};
  const int SIZE = 6;

  quickSort(arr, 0, SIZE -1);

  for(int i = 0; i < SIZE; i++) 
    cout << arr[i] << endl;
  
  return 0;
}
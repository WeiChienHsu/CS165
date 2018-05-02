#include <iostream>
using namespace std;

void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int arr[], int i, int j);


void quickSort(int arr[], int start, int end) {
  if(start >= end) return;
  int partitionIndex = partition(arr, start, end);
  cout << "PartitionIndex:" << partitionIndex << endl;
  quickSort(arr, start, partitionIndex - 1);
  quickSort(arr, partitionIndex + 1, end);
}


int partition(int arr[], int start, int end) {
  int partitionIndex = start; // 界線
  int pivot = arr[end];
  for(int i = start; i < end; i++) {
    if(arr[i] <= pivot) {
      swap(arr, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap(arr, end, partitionIndex);
  return partitionIndex;
}


void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main() {
  int arr[] = {5,3,2,7,1,4};
  quickSort(arr,0, 5);

  for(int i = 0; i < 6; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
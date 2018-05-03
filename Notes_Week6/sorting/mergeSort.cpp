#include <iostream>
using namespace std;

void mergeSort(int arr[], int size);

void merge(int arrA[], int arrL[], int leftCount, int arrR[], int rightCount);

void merge(int arrA[], int arrL[], int leftCount, int arrR[], int rightCount) {
  int i = 0, j = 0, k = 0;
  // i - to mark the index of left subarray(L)
  // j - to mark the index of right subarray(R)
  // k - to mark the index of merged array(A)

  while(i < leftCount && j < rightCount) {
    if(arrL[i] < arrR[j]) {
      arrA[k++] =arrL[i++];
    } else {
      arrA[k++] = arrR[j++];
    }
  }
  while( i < leftCount) arrA[k++] = arrL[i++];
  while( j < rightCount) arrA[k++] = arrR[j++];
}

void mergeSort(int arr[], int size) {
  if(size == 1) return;
  int mid = size / 2;

  int* L = new int[mid];
  int* R = new int[size - mid];

  int k = 0;

  for(int i = 0; k < mid; i++) L[i] = arr[k++];
  for(int i = 0; k < size; i++) R[i] = arr[k++];

  mergeSort(L, mid);
  mergeSort(R, size - mid);

  merge(arr, L, mid, R, size - mid);
  delete[](L);
  delete[](R);
}

int main() {
  int arr[] = {1,5,3,10,9,7};
  mergeSort(arr, 5);

  for(int i = 0; i < 5; i++)
    cout << arr[i] << endl;
}
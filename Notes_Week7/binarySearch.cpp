#include <iostream>
using namespace std;

int binarySearch_rec(int arr[], int start, int end, int target) {
  if(start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2;

  if(arr[mid] == target) {
    return mid;
  } else if(arr[mid] > target) {
    return binarySearch_rec(arr, start, mid -1, target);
  } else {
    return binarySearch_rec(arr, mid + 1, end, target);
  }
}

int main() {
  int arr[5] = {1,3,4,7,10};

  cout << binarySearch_rec(arr, 0, 4, 7);
  return 0;
}
#include <iostream>
using namespace std;

bool isDecreasing(int arr[], int size) {
 
    if(size <= 0) {
      return true;
    } else if(arr[size] >= arr[size - 1]) {
      return false;
    } else {
      return isDecreasing(arr, size - 1);
    }
}

int main() {
  int arr[]  = {1,2,3,4,5};
  int arr2[] = {5,4,3,2,1};
  int arr3[] = {5,4,4,3,2};
  cout << isDecreasing(arr, 5) << endl;
  cout << isDecreasing(arr2, 5) << endl;
  cout << isDecreasing(arr3, 5) << endl;

  return 0;
}
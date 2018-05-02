#include <iostream>
using namespace std;

int arrayMax(int arr[], int size) {
  if(size == 0) return 0;

  if(arr[size - 1] > arrayMax(arr, size - 1)) {
    return arr[size - 1];
  } else {
    return arrayMax(arr, size - 1);
  }
}

int main() {
  int arr[] = {1,2,4,10,22,34,1,0,33,35,3};
  cout << arrayMax(arr, 11) << endl;
  return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Template for minimum of an array
template <class T>
T minimun(T arr[], int size) {
  T smallest = arr[0];
  for(int i = 0; i < size; i++) {
    if(arr[i] < smallest) {
      smallest = arr[i];
    }
  }
  return smallest;
}

int main() {
  int arr[] = {1,5,3,2};
  cout << minimun(arr, 4) << endl;
  return 0;
}
#include <iostream>
using namespace std;

double summer(double arr[], int size) {
  if(size == 0) return 0;
  return arr[size - 1] + summer(arr, size - 1);
}

int main() {
  double arr[] = {1.0, 1.5, 10.0};
  cout << summer(arr, 3) << endl;
  return 0;
}
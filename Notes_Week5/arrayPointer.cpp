#include <iostream>
using namespace std;
int main() {
  int arr[] = {1,2,3,4};
  int* arrPtr;

  arrPtr = arr;

  for(int i = 0; i < 4; i++) {
    cout << *(arrPtr + i) << endl;
  }
  return 0;
}
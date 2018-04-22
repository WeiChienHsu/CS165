#include <iostream>
using namespace std;

int main() {
  int arr[2][4] = {{0,2,4,6},{1,1,1,1}};
  int *pInt1 = &arr[0][0];
  cout << "Address of arr[0][0]:  " << pInt1 << endl;
  pInt1++;
  cout << "Value of arr[0][1]:  " << *pInt1 << endl;

  int *pInt2 = arr[0];
  cout << "Address of arr[0] which means first row: " << pInt2 << endl;
  pInt2++;
  cout << "Second number in first row: " << *pInt2 << endl;

  int (*pint3)[4] = arr;
  

   
  return 0;
}
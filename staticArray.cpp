#include <iostream>
#define ELE 5
using namespace std;

int main() {
  int arr[ELE];
  int i, size;


  cout << "Array Location : " << arr << endl;
  cout << "Array pointer location : " << &arr << endl;

  for(i = 0; i < ELE; i++) 
    arr[i] = i;
  
  for(i = 0 ;i < ELE; i++)
    cout << "Initial contnets: " << arr[i]  << " | Address of elements: " << &arr[i] << endl;

  
  int *dynarr;
  dynarr = new int[ELE];
  cout << "Array pointer location : " << &dynarr << endl;
    cout << "Array Location on the Heap : " << dynarr << endl;

  for(i = 0; i < ELE; i++) 
    dynarr[i]   =  i;

  for(i = 0 ;i < ELE; i++)
    cout << "Initial contnets: " << dynarr[i] << " | Address of elements in Heap: " << &dynarr[i]<< endl;

  delete[] dynarr;

  return 0;
}
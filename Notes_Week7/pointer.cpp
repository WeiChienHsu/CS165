#include <iostream>
using namespace std;
int main() {
  // int n = 3;
  // int *ptr = NULL;
  // ptr = &n;


  // cout << "ptr stand for the address it points to: " << ptr << endl;
  // cout << "Thee address we assign to the pointer by ptr = &n " << &n << endl;
  // cout << "&ptr stand for the address of pointer itself: " << &ptr << endl;
  // cout << "*ptr deference the address it points to: "<< *ptr << endl;

  // *ptr = 5;

  // cout << "*ptr = 5 could chagne the value stored in the address pointer pointed to : " << ptr << endl;
  // cout << "Value equal to = *ptr : " << *ptr << endl;

  int n = 3;
  int* newPtr = new int;
  *newPtr = 3;
  
  cout << "ptr stand for the address it points to: " << newPtr << endl;
  
  delete newPtr;

  return 0;
}
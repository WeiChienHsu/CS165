#include <iostream>
using namespace std;


// Pass by Reference
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
  cout << "x: " << x << "  " << "y: " << y << endl;
  cout << "address of x: " << &x << "   " << "address of y: " << &y << endl;
  cout << "###########################\n"; 
}

// Used the pointer
void swap_point(int *x, int *y) {
  int temp = *x;
  cout << "address of x: " << x << "  " << "address of y: " << y << endl;
  cout << "address of x's address stored: " << &x << "  " << "address of y's address stored: " << &y << endl;
  cout << "x : " << *x << "    " << "y : " << *y << endl;
}


int main() {

  int a, b, c, d;
  a = 10;
  b = 100;
  c = 10;
  d = 100;
  swap(a,b);
  swap_point(&c, &d);
  
  return 0;
}
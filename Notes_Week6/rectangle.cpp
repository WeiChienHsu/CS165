#include <iostream>
using namespace std;

void draw_rectangle_iter(int num) {
  for( ;num > 0; num--) {
    cout << "**********" << endl;
    cout << "*   " << num << "    *" << endl;
    cout << "**********" << endl;
  }
}

void draw_rectangle_rec(int num) {
  if(num > 0) {
    draw_rectangle_rec(--num);
    cout << "**********" << endl;
    cout << "*   " << num << "    *" << endl;
    cout << "**********" << endl;
  }
}

int main() {
  cout << "Iteration:  " << endl;
  draw_rectangle_iter(4);
  cout << "Recursive:  " << endl;
  draw_rectangle_rec(4);
  return 0;
}
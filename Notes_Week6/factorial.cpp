#include <iostream>
using namespace std;

int factorial(int num) {
  if(num == 1) {
    return 1;
  }
  cout << "Current num: " << num << endl;
  return num * factorial(num - 1);
}

int main() {
  cout << factorial(4) << endl;

  return 0;
}
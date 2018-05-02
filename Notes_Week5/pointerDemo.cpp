#include <iostream>
using namespace std;

int main() {
  int x = 10, userInput;
  int *ptr = &x;


  cout << "X equal to: " << *ptr << endl;
  cout << "Please input value to change x \n";
  cin >> userInput;

  *ptr = userInput;

  cout << "New Value is :" << *ptr << endl;
  return 0;
}
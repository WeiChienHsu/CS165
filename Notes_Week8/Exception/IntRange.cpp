#include "IntRange.hpp"
#include <iostream>
using namespace std;

IntRange::IntRange(int low, int high) {
  this->lower = low;
  this->upper = high;
}

int IntRange::getInput() {
  cin >> this->input;
  if(this->input < this->lower || this->input > this->upper) {
    throw IntRange::OutOfRange(input);
  }
  return this->input;
}

IntRange::OutOfRange::OutOfRange(int input) {
    this->value = input;
}


int main() {
  IntRange range(5, 10);
  int userValue;

  cout << "Enter a value in the range 5 - 10: " << endl;
  
  try {
    userValue = range.getInput();
    cout << "You entered: " << userValue << endl;
  }

  catch(IntRange::OutOfRange e) {
    cout << "That value " << e.value << " is our of range. \n";
  }

  cout << "End of the program \n";
  return 0;
}

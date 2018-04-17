/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  A void function named smallSort that takes three int parameters 
                 by reference and sorts their values into ascending order, so 
                 that the first parameter now has the lowest value, the second 
                 parameter the middle value, and the third parameter has the 
                 highest value.

  
*********************************************************************/

#include <iostream>

/*********************************************************************
These two functions' parameters are a reference variables.
This means it receives a reference to the original variable passed
to it, rather than a copy of that variable's data.
*********************************************************************/

void exchange(int& large, int& small) {
  int temp = large;
  large = small;
  small = temp;
}

void smallSort(int& first, int& second, int& third) {
  // To Make sure the first number is the smallest number
  if(first > second) {
    exchange(first, second);
  }

  if(first > third) {
    exchange(first, third);
  }

  // To Make sure second number is smaller than third number
  if(second > third) {
    exchange(second, third);
  }
}

// int main() {
//   int first = 4;
//   int second = 5;
//   int third = 3;
//   smallSort(first, second, third);
//   std::cout << first << ", " << second << ", " << third << std::endl;
// }
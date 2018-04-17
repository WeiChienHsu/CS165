/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  Program takes the starting integer as "a parameter" and 
                 returns how many steps it takes to reach 1 first time.

                 If that integer is even, then you divide it by two to 
                 get the next integer in the sequence, but if it is odd, 
                 then you multiply it by three and add one to get the 
                 next integer in the sequence.
  
*********************************************************************/
#include <iostream>

int hailstone(int number) {
  int currentNumber = number, count = 0;
  // Deal with an invalid number 0 in this case
  // This one not required by the project,
  // but I found out this issue when testing.
  if(currentNumber == 0) {
    return 0;
  }

  // While currentNumber doesn't equal to 1
  // keep tracking the next number in the sequence
  while(currentNumber != 1 ) {
    // Count the steps after meeting one
    count++;
    if(currentNumber % 2 == 0) {
       // When currentNumber is Even
       currentNumber /= 2;
    } else {
       // When currentNumber is Odd
       currentNumber = currentNumber * 3 + 1;
    }
  }
  return count;
}

// int main() {
//   int startNumber, steps;
//   std::cout << "Please enter a start number: \n";
//   std::cin >> startNumber;
//   steps = hailstone(startNumber);
//   std::cout << steps << std::endl;

//   return 0;
// }
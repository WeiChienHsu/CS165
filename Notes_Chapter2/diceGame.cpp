/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/08/18
** Description:  User input an Integer from 1 - 6 and program will output 
                 your secion in the game. (Practice Switch syntax)
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
  
  int number;
  cout << "Please enter the number from 1 - 6: " << endl;
  cin >> number;

  switch(number) {
    case 1:
      cout << "Welcome to Number one Club" << endl;
      break;
    case 2:
      cout << "Welcome to Number two Club" << endl;
      break;
    default:
      number >= 5?  
      cout << "Welcome to the BIG NUMBER Club" << endl  : cout << "Welcome to the SMALL Club" << endl;
     
  }

  return 0;
}
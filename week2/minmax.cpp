/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Asks the user how many integers they would like to enter and 
                 Prompt the user to enter that many integers. In the end,
                 Display the Largest and Smallest of those numbers.
*********************************************************************/

#include <iostream>
using namespace std;
int main() {
  int numberOfInt, maxInt, minInt, currentInt;

  cout << "How many integers would you like to enter?" << endl;
  cin >> numberOfInt;
  cout << "Please enter " << numberOfInt << " integers." << endl;
  cin >> currentInt;
  
  // In order to limit the input from user.
  // After user enters one integer, total number of Integer should minus one
  numberOfInt--;

  // Init the Min Interger and Max Integer
  maxInt = currentInt;
  minInt = currentInt;

  // While numberOfInt is greater than zero, user could enters more number
  while(numberOfInt > 0) {
    cin >> currentInt;
    
    // After user enters one integer, total number of Integer should minus one
    numberOfInt--;
    
    if(currentInt > maxInt) {
      maxInt = currentInt;
    }

    if(currentInt < minInt) {
      minInt = currentInt;
    }
  }

  cout << "min: " << minInt << endl;
  cout << "max: " << maxInt << endl;

  return 0;

}
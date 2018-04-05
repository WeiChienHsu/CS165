/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/02/18
** Description:  Asks the user to input a Celsius temperature and 
                 should display the corresponding Fahrenheit temperature.
                 It should display only the converted temperature without 
                 any text (not even a 'F').  
*********************************************************************/

#include <iostream>
using namespace std;

int main() { 

  double tempInC;
  double tempInF;

  cout << "Please enter a Celsius temperature." << endl;
  cin >> tempInC;

  tempInF = (tempInC * 9.0) / 5.0 + 32.0;

  cout << "The equivalent Fahrenheit temperature is: " << endl;
  cout << tempInF << endl;

  return 0;
}
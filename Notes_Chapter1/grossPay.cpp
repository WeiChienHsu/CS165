/******************************************
** This Program calculates the user's pay
*******************************************/

#include <iostream>
using namespace std;

int main() {
  double hours, rate, pay;

  // Get the number of hours worked
  cout << "How many hours did you work daily?" << endl;
  cin >> hours;

  // Get the hourly pay rate
  cout << "How much do you get paid per hour?" << endl;
  cin >> rate;

  // Calculate the pay
  pay = hours * rate;

  // Display the pay
  cout << "You have earned $" << pay << " everyday" << endl;
  return 0;
}
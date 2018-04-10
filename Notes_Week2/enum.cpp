/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  This program demonstrates an enumerated data type.
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

enum Roster { Tom = 1, Sharon, Bill, Teresa, John}; 
// Sharon - John wil be assigned default values 2-5
// Tom = 1 (Tom not a string anymore)

int main() {
  int who;
  cout << "This program will let you know people's birthday," << endl;
  cout << setw(10) << "Tom - 1" << endl;
  cout << setw(10) << "Sharon - 2" << endl;
  cout << setw(10) << "Bill - 3" << endl;
  cout << setw(10) << "Teresa - 4" << endl;
  cout << setw(10) << "John - 5" << endl;
  cout << "Enter 1 - 5 to know: " << endl;
  cin >> who;

  switch(who){
    case Tom:
      cout << "Tom's birthday is on 5/3" << endl;
      break;
    case Sharon:
      cout << "Sharon's birthday is on 5/3" << endl;
      break;
    case Bill:
      cout << "Bill's birthday is on 5/3" << endl;
      break;
    case Teresa:
      cout << "Teresa's birthday is on 5/3" << endl;
      break;
    case John:
      cout << "John's birthday is on 5/3" << endl;
      break;
    default:
      cout << "Please enter a right number" << endl;
  }

  return 0;
}
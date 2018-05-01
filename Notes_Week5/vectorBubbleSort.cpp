/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/30/18
** Description:  Implement bubble Sort to the vector 
*********************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void displayVector(vector<int>);
void sortVector(vector<int> &);

int main() {
  const int SIZE = 6;
  vector<int> values(SIZE);

  cout << "Please enter " << SIZE << " Integers separated by spaces. \n";
  for(int i = 0; i < SIZE; i++) {
    cin >> values[i];
  }

  cout << "\n The unsorted values entered are : \n";
  displayVector(values);

  sortVector(values);
  cout << "\n Sorted Vector are: \n";
  displayVector(values); 
  return 0;
}

/*********************************************************************
** Function:     sortVector(vector<int> &);
** Argument:  The reference(Address) of vector
** Return  :  Void. But it will use passing by reference to change 
**            the origin value of vector in the main function stack
*********************************************************************/

void sortVector(vector<int> &number) {
  int temp;
  bool swaped = false;

  do{
    swaped = false;
    for(int i = 0; i < number.size() - 1; i++) {
      if(number.at(i) > number.at(i+1)) {
        temp = number.at(i);
        number.at(i) = number.at(i+1);
        number.at(i+1) = temp;
        swaped = true;
      }
    }
  } while (swaped);
}

void displayVector(vector<int> number) {
  for(int i = 0; i < number.size(); i++) {
    cout << number.at(i) << endl;
  }
}

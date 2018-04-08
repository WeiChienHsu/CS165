/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/08/18
** Description:  User input an Integer and program will output it's all factors.
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
    int number;
    int countFactor = 0;

    cout << "Please enter a Integer: " << endl;
    cin >> number;
    cout << "Factors of " << number << "is: " << endl;
    for(int i = 1; i <= number; i++) {
      if(number % i == 0) {
        countFactor++;
        cout << "The " << countFactor << " factor is: " << i << endl;
      }
    }

    return 0;
}
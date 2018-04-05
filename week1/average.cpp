/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/02/18
** Description:  Asks the user for five numbers and then prints out
                 the average of those numbers.
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
    double num1;
    double num2;
    double num3;
    double num4;
    double num5;

    cout << "Please enter five numbers." << endl;
    cin >> num1;
    cin >> num2;    
    cin >> num3;
    cin >> num4;
    cin >> num5;

    double averageNumber = (num1 + num2 + num3 + num4 + num5) / 5.0;

    cout << "The average of those numbers is:" << endl;
    cout << averageNumber << endl;

    return 0;
}
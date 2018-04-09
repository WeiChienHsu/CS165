/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/04/18
** Description:  Write a program that calculates how much a Little League 
                 baseball team spent last year to purchase new baseballs.
                 User enter the number of baseballs purchases and the cost 
                 of each baseballs and program should display total cost.
*********************************************************************/


#include <iostream>
using namespace std;

int main() {
    int numOfBall;
    double singleCostOfBall;
    double totalCost;

    cout << "Please enter the number of baseballs purchased:  ";
    cin >> numOfBall; 
    cout << "Please enter the cost of each baseballs:  ";
    cin >> singleCostOfBall;

    totalCost = singleCostOfBall * numOfBall;

    cout << "You spent total $" << totalCost << " on purchasing baseballs" << endl;
    return 0;

}
/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/02/18
** Description:  Asks the user for a (integer) number of cents, 
                 from 0 to 99, and outputs how many of each type 
                 of coin would represent that amount with the 
                 fewest total number of coins.  
*********************************************************************/

#include <iostream>
using namespace std;

/********************************************************************* 
** Description: Getting to know how many quarter we need by using 
                the User Input Value divided by 25 and keep tracking 
                the remain Value by doing the modular arithmetic. 
                Same methods to the dime, nickel and penny by 10, 5
                and 1.
                
                For Example, we got an input of 87
                Quarter We Needed: 87 / 25 = 3 
                The Remain Value now is : 12 (Which is equal to 87 % 25)
                
                Dime We Needed: 12 / 10 = 1
                The Remain Value now is : 2 (Which is equal to 12 % 10)
                
                Nickel We Needed: 2 / 5 = 0
                The Remain Value now is : 2 (Which is equal to 2 % 5)                
                
                Penny We Needed is the current Remain Value: 2               
*********************************************************************/ 

int main() {
    int remainCents = 0;
    int quarterNumber = 0;
    int dimeNumber = 0;
    int nickelNumber = 0;
    int pennyNumber = 0;

    cout << "Please enter an amount in cents less than a dollar." << endl;
    cin >> remainCents;

    quarterNumber = remainCents / 25;
    remainCents = remainCents % 25;
    dimeNumber = remainCents / 10;
    remainCents = remainCents % 10;
    nickelNumber = remainCents / 5;
    remainCents = remainCents % 5;
    pennyNumber = remainCents;

    cout << "Your change will be:" << endl;
    cout << "Q: " << quarterNumber << endl;
    cout << "D: " << dimeNumber << endl;
    cout << "N: " << nickelNumber << endl;
    cout << "P: " << pennyNumber << endl;

    return 0;    
}
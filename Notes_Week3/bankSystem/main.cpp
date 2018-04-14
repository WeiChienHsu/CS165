/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The Account Class record the States of:
                 1) current Balance
                 2) current interest Rate
                 3) current total interest
                 4) Total Transcation

                Interface:
                  Constructor: Account account(int intRate, int balance)
                  void makeDeposit(double amount)
                  bool withdraw(double aomount)
                  void calcInterest()
                  double getBalance()
                  double getInterest()
                  int getTransactions()
                
                Demand:
                  1) Display the account balance
                  2) Display the number of transactions
                  3) Display interest earned for this period
                  4) Make a deposit
                  5) Make a withdrawal
                  6) Add interest for this period
                  7) Exit the program
*********************************************************************/


#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Account.cpp"

using namespace std;

void getMenu();
char readSelection(char);
// When making a Deposit, we need to change the value of
// balance in the Object, so we need to use reference argument
void makeDeposit(Account &);
void makeWithdrawal(Account &);

int main() {
  char selection;
  const char MAX_SELECTION = '7';
  
  Account newAccount; // Initize a new Object

  // Run this program first time
  do {
    // Print out all Choices for user
    getMenu();

    // Read the input(selection) from user
    selection = readSelection(MAX_SELECTION);

    // Conditional Behaviors from users selections
    switch(selection) {
      case '1': cout << "The current Balance is : $" << newAccount.getBalance() << endl;
                break;

      case '2': cout << "The number of transactions are : " << newAccount.getTransactions() << endl;
                break;

      case '3': cout << "Interest earned : $" 
                << newAccount.getInterest() << endl;
                break;

      case '4': makeDeposit(newAccount);
                break;

      case '5': makeWithdrawal(newAccount);
                break;

      case '6': newAccount.calcInterest();
                cout << "Interest added." << endl;
                cout << "Now have: $" << newAccount.getInterest() << endl;
                break; 
    }
  } while (selection != '7');
  
  // End the program
  return 0;
}

void makeWithdrawal(Account &account) {
  double dollor;
  cout << "Now you have : $" << account.getBalance() << endl;
  cout << "Please enter the amount you want to withdraw: " << endl;
  cin >> dollor;
  cin.ignore();
  if(account.withdraw(dollor)) {
    cout << "Wothdraw : $ " << dollor << endl;
    cout << "Now Your Balance is: $" << account.getBalance() << endl;
  } else {
    cout << "You don't have enough money in your bank!\n";
    cout << "Remind: $" << account.getBalance();
  }
}

void makeDeposit(Account &account) {
  double dollor;
  cout << "Please enter the amount you want to deposit: " << endl;
  cin >> dollor;
  cin.ignore();
  account.makeDeposit(dollor);
}

char readSelection(char MAX_SELECTION) {
  char selection = cin.get();
  cin.ignore();

  while(selection < '1' || selection > MAX_SELECTION) {
    cout << "Choice must between 1 and " << MAX_SELECTION << "Please Enter again: ";
    selection = cin.get();
    cin.ignore();
  }

  return selection;
}

void getMenu() {
  cout << "####################" << endl;
  cout << " Menu " << endl;
  cout << "1) Display the account balance" << endl;
  cout << "2) Display the number of transactions" << endl;
  cout << "3) Display interest earned for this period" << endl;
  cout << "4) Make a deposit" << endl;
  cout << "5) Make a withdrawl" << endl;
  cout << "6) Add interest for this period" << endl;
  cout << "7) Exit the program" << endl;
  cout << "Enter your choice: " << endl;
  cout << "####################" << endl;
}
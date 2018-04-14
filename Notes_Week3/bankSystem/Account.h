#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
  private:
    double balance;
    double intRate;
    double interest;
    int transactions;

  public:
    Account(double rate = 0.045, double bal = 0.0) {
      intRate = rate; balance = bal; interest = 0.0; transactions = 0;
    }

    void makeDeposit(double amount) {
      balance += amount;
      transactions++;
    }

    bool withdraw(double amount); //Defined in account.cpp

    void calcInterest() {
      interest = balance * intRate;
      balance += interest;
    }

    double getBalance() {
      return balance;
    }

    double getInterest() {
      return interest;
    }

    int getTransactions() {
      return transactions;
    }
};


#endif
#ifndef BUDGET_HPP
#define BUDGET_HPP
#include

class Budget {
  private:
    static double corpBuget;
    double divBudget;
  public:
    Budget() { divBudget = 0;}
    void addBudget(double b) {
      this->divBudget += b;
      this->corpBuget += divBudget;
    }

    double getDivBudget() const {return this->divBudget;}
    friend void Aux::addBudget(double);
};
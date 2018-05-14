#ifndef BUDGET_HPP
#define BUDGET_HPP
#include "aux.hpp"

class Budget {
  private:
    static double corpBudget;
    double divBudget;
  public:
    Budget() { divBudget = 0;}
    void addBudget(double b) {
      this->divBudget += b;
      this->corpBudget += divBudget;
    }

    double getDivBudget() const {return this->divBudget;}
    static double getCorpBudget() {return corpBudget;} 
    friend void Aux::addBudget(double);
};

#endif
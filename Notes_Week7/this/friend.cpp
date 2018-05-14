#include <iostream>


class Aux {
  private:
    double auxBudget;
  public:
    Aux() { auxBudget = 0; }
    void addBudget(double num) {
      this->auxBudget += num;
      Budget::addBudget(auxBudget);
    }
};


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

double Budget::corpBuget = 0;


int main() {
  Budget a;
  a.addBudget(10);
  a.getDivBudget();

  return 0;
}
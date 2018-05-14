#ifndef AUX_HPP
#define AUX_HPP

class Aux {
  private:
    double auxBudget;
  public:
    Aux() { auxBudget = 0; }
    void addBudget(double);
    double getDivBudget() const { return auxBudget;}   
};


#endif

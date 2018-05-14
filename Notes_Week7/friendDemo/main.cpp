#include <iostream>
#include "budget.hpp"

int main() {
  Budget a;
  a.addBudget(10);
  std::cout << a.getCorpBudget() << std::endl;

  Aux b;
  b.addBudget(100);
  
  std::cout << a.getCorpBudget() << std::endl;

  return 0;

}
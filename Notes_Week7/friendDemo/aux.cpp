#include "aux.hpp"
#include "budget.hpp"

// Define the friend function

void Aux::addBudget(double b) {
  auxBudget += b;
  Budget::corpBudget += auxBudget;
}
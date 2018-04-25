/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/24/18
** Description:  Test file with main Function.
*********************************************************************/
#include <iostream>
#include "Person.hpp"

double setDev(Person *arr, int size);

int main() {
  // Init those Person objects

  Person a = Person("Kevin", 9);
  Person b = Person("Peter", 2);
  Person c = Person("Kevin", 5);
  Person d = Person("Peter", 4);
  Person e = Person("Kevin", 12);
  Person f = Person("Peter", 7);

  // Init the Person Array
  Person personList[] = {a, b, c, d, e, f};

  std::cout << setDev(personList, 6) << std::endl;
  return 0;
}
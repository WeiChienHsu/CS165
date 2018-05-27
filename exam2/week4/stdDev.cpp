#include "Person.hpp"
#include <iostream>
#include <string>

double stdDev(Person* arr, int size) {
  double sum = 0.0;
  for(int i = 0; i < size; i++) {
    sum += arr[i].getAge();
  }
  return sum;
}

int main() {
  Person a = Person("Kevin", 20.2);
  Person b = Person("Peter", 30.1);
  Person c = Person("Jerry", 15.0);

  Person personArray[3] = {a, b, c};
  std::cout << stdDev(personArray, 3) << std::endl;
  return 0; 
}
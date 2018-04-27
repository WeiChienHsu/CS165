/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:   A class called Person that has two data members 
                    - a string variable called name and a double variable called age. 

                  It should have a constructor that takes two values and uses them to 
                  initialize the data members.  

                  It should have get methods for both data members (getName and getAge), 
                  but doesn't need any set methods.
*********************************************************************/

#include <iostream>
#include <vector>
#include "Person.hpp"

// int personSearch() {

// }

int binarySearch(std::vector<Person> &vec, double target) {
  int start = 0;
  int end = vec.size() - 1;

  while(start + 1 < end) {
    int middle = start + (end - start) / 2;
    if(vec.at(middle).getAge() == target) {
      start = middle;
    } else if(vec.at(middle).getAge() < target) {
      start = middle;
    } else {
      end = middle;
    }
  }

  if(vec.at(start).getAge() == target) {
    return start;
  }

  if(vec.at(end).getAge() == target) {
    return end;
  }

  return -1;
}

int main() {
  std::vector<Person> vec;
  Person p1 = Person("Kevin", 22);
  Person p2 = Person("Peter", 33);
  Person p3 = Person("Kids", 10);

  vec.push_back(p1);
  vec.push_back(p2);
  vec.push_back(p3);

  // for(int i = 0; i < 5; i++) {
  //   vec.push_back(i);
  // }

  for(int i = 0; i < vec.size(); i++) {
    std::cout << vec.at(i).getName() << std::endl;
  }

  std::cout << "Find 33 Year old man at index of: " << binarySearch(vec, 33) << std::endl;
  return 0;
}
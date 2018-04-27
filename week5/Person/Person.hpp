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
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person {
  private:
    std::string name;
    double age;
  public:
    Person();
    Person(std::string, double);
     std::string getName() const;
     double getAge() const;
};

#endif
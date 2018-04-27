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
# include <iostream>
# include "Person.hpp"

/***********************************
** Default Constructor
** initialize the data members.
************************************/
Person::Person() {
  name = "";
  age = 0.0;
}

/***********************************
** Constructor
** takes two values and uses them to 
** initialize the data members.
************************************/
Person::Person(std::string thisName, double thisAge) {
  name  = thisName;
  age = thisAge;
}

/***********************************
** Getter Function
** Get the string of name.
************************************/
 std::string Person::getName() const {
  return name;
}

/***********************************
** Getter Function
** Get age in double.
************************************/
 double Person::getAge() const {
  return age;
}

#include <iostream>
#include <string>

class Person {
  private:
    std::string name;
    double age;
  public:
     Person(std::string name, double age) {
       this->name = name;
       this->age = age;
     }
     std::string getName() const {
       return this->name;
     }

     double getAge() const {
       return this->age;
     }
};
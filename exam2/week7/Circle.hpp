#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "Shape.hpp"
#include <iostream>

class Circle : public Shape {
  public:
    Circle(double r) {
      setRadius(r);
    }

    void setRadius(double r) {
      this->radius = r;
    }
    // Override
    double area(){
      const double PI = 3.14159;
      return this->radius * this->radius * PI;
    }

    double perimeter() {
      const double PI = 3.14159;
      return this->radius * 2 * PI;
    }

  protected:
    double radius;
};
#endif
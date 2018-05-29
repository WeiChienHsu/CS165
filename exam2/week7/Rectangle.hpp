#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp"
#include <iostream>

class Rectangle : public Shape {
  public:
    Rectangle(double l, double w) {
      setLength(l);
      setWidth(w);
    }


    virtual void setLength(double l) {
      this->length = l;
      std::cout << "Set Rectangle(Length)" << std::endl;
    }

    virtual void setWidth(double w) {
      this->width = w;
      std::cout << "Set Rectangle(Width)" << std::endl;
    }

    // Override
    double area() {
      return this->length * this->width;
    }

    double perimeter() {
      return (this->length + this->width) * 2;
    }

  protected:
    double length;
    double width;
};
#endif
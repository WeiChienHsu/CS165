#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Rectangle.hpp"
#include <iostream>

class Square : public Rectangle {
  public:
    Square(double side) : Rectangle(side, side) {
        setLength(side);
        setWidth(side);
        std::cout << "Pass side into Rectangle instances from Square class" << std::endl;
      }
    

    // override 
    void setLength(double l) {
      this->length = l;
      this->width = l;
      std::cout << "Set Square(Length)" << std::endl;
    }

   void setWidth(double w) {
      this->length = w;
      this->width = w;
      std::cout << "Set Square(Width)" << std::endl;
    }

    double area() {
      return this->length * this->width;
    }

    double perimeter() {
      return (this->length + this->width) * 2;
    }

  private:
    double width;
    double length;
};

#endif
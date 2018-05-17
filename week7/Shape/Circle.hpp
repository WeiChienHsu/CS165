/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A class called Circle that inherits from Shape. 
                 have a double field for it's radius
                 have a set method for the radius
                 have a constructor that takes a double parameter and passes it to the set method
                 Override the Shape virtual methods to return the area and perimeter of a Circle
*********************************************************************/
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Shape.hpp"

class Circle : public Shape {
  public:

    // Constructor: take a double parameter 
    Circle(double);
    // Override virtual methods
    double area();
    double perimeter();

  private:
    // double field for the radius
    double radius;
    // Set Method : Only make constructor could access set method
    void setRadius(double);
};

#endif
/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A class called Rectangle that inherits from Shape
                 have double fields for its length and width.
                 have virtual set methods for both fields
                 have a constructor that takes two double parameters and passes them to the set methods.
                 override the Shape virtual methods to return the area and perimeter of a Rectangle.
*********************************************************************/
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp"

class Rectangle : public Shape {
  public:
    // Constructor: take two double parameter 
    Rectangle(double, double);
    // Override virtual methods
    double area();
    double perimeter();

  protected:
    // Virtual Set Method : Put in protected since I will be accessed by child class
    virtual void setLength(double);
    virtual void setWidth(double);

  private:
    // double field for the length and width.
    double length;
    double width;
};

#endif
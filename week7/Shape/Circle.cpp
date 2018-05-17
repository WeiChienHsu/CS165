/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A class called Circle that inherits from Shape. 
                 have a set method for the radius
                 have a constructor that takes a double parameter and passes it to the set method
                 Override the Shape virtual methods to return the area and perimeter of a Circle.
                 (use 3.14159 for pi).
*********************************************************************/
# include <iostream>
# include "Circle.hpp"

/***********************************
** setRadius
** take a double paramter for the radius
************************************/
void Circle::setRadius(double r) {
  this->radius = r;
}

/***********************************
** Constructor
** takes a double parameter and passes it to the set method
************************************/
Circle::Circle(double r) {
  this->setRadius(r);
}

/***********************************
** area()
** Override the Shape virtual methods to return the area
************************************/
double Circle::area() {
  const double PI = 3.14159; 
  return (this->radius) * (this->radius) * PI;
}

/***********************************
** perimeter()
** Override the Shape virtual methods to return the perimeter
************************************/
double Circle::perimeter() {
  const double PI = 3.14159; 
  return (this->radius) * 2.0 * PI;
}
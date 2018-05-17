/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A class called Rectangle that inherits from Shape
                 have double fields for its length and width.
                 have virtual set methods for both fields
                 have a constructor that takes two double parameters and passes them to the set methods.
                 override the Shape virtual methods to return the area and perimeter of a Rectangle.
*********************************************************************/
# include <iostream>
# include "Rectangle.hpp"

/***********************************
** setLength
** take a double paramter for the length
************************************/
void Rectangle::setLength(double l) {
  this->length = l;
}

/***********************************
** setWidth
** take a double paramter for the width
************************************/
void Rectangle::setWidth(double w) {
  this->width = w;
}

/***********************************
** Constructor
** takes two double parameters and passes them to the set methods.
************************************/
Rectangle::Rectangle(double l, double w) {
  this->setLength(l);
  this->setWidth(w);
}

/***********************************
** area()
** Override the Shape virtual methods to return the area
************************************/
double Rectangle::area() {
  return (this->length) * (this->width);
}

/***********************************
** perimeter()
** Override the Shape virtual methods to return the perimeter
************************************/
double Rectangle::perimeter() {
  return ((this->length) + (this->width)) * 2.0;
}
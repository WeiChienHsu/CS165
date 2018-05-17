/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A class called Square that inherits from Rectangle
                 Have a constructor that takes one double parameter 
                 and passes it to the base class constructor for both 
                 parameters (the body of the constructor will be empty).

                 
                 Override the virtual setLength() and setWidth() functions 
                 of its base class such that if either of its dimensions is 
                 set to a new value, then both of its dimensions will be set 
                 to that new value (so that it remains a square).
*********************************************************************/
# include <iostream>
# include "Square.hpp"

/***********************************
** Constructor
** takes one double parameter 
** and passes it to the base class constructor for both 
** parameters (the body of the constructor will be empty).
************************************/
Square::Square(double side) : Rectangle::Rectangle(side, side) {
  // the body of the constructor will be empty
}

/***********************************
** setLength(double)
** Override the virtual setLength() functions of its base class 
************************************/
void Square::setLength(double side) {
  Rectangle::setLength(side);
}

/***********************************
** setWidth(double)
**  Override the virtual setWidth() functions of its base class 
************************************/
void Square::setWidth(double side) {
  Rectangle::setWidth(side);
}


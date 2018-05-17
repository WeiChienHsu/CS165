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
#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Rectangle.hpp"

class Square : public Rectangle {
  public:
    // Constructor: takes one double parameter 
    Square(double);
    
  protected:
    // Override virtual methods setLength() and setWidth()
    void setLength(double);
    void setWidth(double);
};

#endif
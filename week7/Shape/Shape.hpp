/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  Abstract class called Shape.  
                 It should have pure virtual methods area and perimeter.
*********************************************************************/
#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
  public:
    // Pure Virtual Function
    virtual int area() = 0;
    virtual int perimeter() = 0;
};


#endif
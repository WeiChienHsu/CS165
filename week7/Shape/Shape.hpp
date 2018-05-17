/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/16/18
** Description:  Abstract class called Shape.  
                 It should have pure virtual methods area and perimeter.
*********************************************************************/
#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
  public:
    // Pure Virtual Function
    virtual double area() = 0;
    virtual double perimeter() = 0;
};


#endif
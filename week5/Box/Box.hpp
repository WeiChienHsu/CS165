/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  The class declaration (interface) for Box. 
                  (Don't need to implement here.)
                  :3 double fields called height, width and length.
                  :A default constructor
                  :3 parameter constructor that takes three doubles.
                  :a method that calculates and returns the volume of the Box
                  :a method that calculates and returns the surface area of the Box.
*********************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

class Box {
  private:
    double height;
    double width;
    double length;

  public:
    Box();
    Box(double, double, double);
    void setHeight(double);
    void setWidth(double);
    void setLength(double);
    double calcVolume();
    double calcSurfaceArea();
};

#endif
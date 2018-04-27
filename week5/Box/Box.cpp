/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The function definitions (implementation) for Box.              
                 Private Values: 3 double fields called height, width and length.
                
                 Implementaion:
                  - Box(): Uses the set methods to initialize each field to 1.
                  - Box(double, double, double): takes three doubles and passes 
                                                 them to the set methods to initialize 
                                                 the fields of the Box.
                  - Three Setter functions: change height, width and length by the argument.
                  - double calcVolume(): Return height * width * length
                  - double calcSurfaceArea(): Return 2*((h * w) + (w * l) + (l * h))
*********************************************************************/


#include <iostream>
#include "Box.hpp"

// Default Constructor
Box::Box() {
  setHeight(1.0);
  setWidth(1.0);
  setLength(1.0);
}

Box::Box(double thisHeight, double thisWidth, double thisLength) {
  height = thisHeight;
  width = thisWidth;
  length = thisLength;
}

// Setter Functions
void Box::setHeight(double thisHeight) {
  height = thisHeight;
}

void Box::setWidth(double thisWidth) {
  width = thisWidth;
}

void Box::setLength(double thisLength) {
  length = thisLength;
}

/******************************************
** calcVolume()
** times height, width and length to return 
** the volume of the box in double data type.
*******************************************/

double Box::calcVolume() {
  return height * width * length;
}

/******************************************
** calcSurfaceArea()
** Count the sum of products from height * width, 
** width * lenght and length * height and times 
** two to get the SurfaceArea of the box in 
** double data type.
*******************************************/


double Box::calcSurfaceArea() {
  return 2 * ((height * width) + (width * length) + (length * height) );
}
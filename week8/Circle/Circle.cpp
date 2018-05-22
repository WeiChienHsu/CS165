/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/21/18
** Description:  a Class named "Circle" that has a double data member 
                 named radius and a static double data member named maxRadius.
               
                1. It should have a default constructor that initializes the radius to 1.0. 
                2. It should have a constructor that takes a double and uses it to initialize the radius.
                3. It should have a method called calcArea that returns the area of the Circle (use 3.14159 for pi).
                4. It should have a static set method for the maxRadius.
                
                5. It should also contain the definition of an exception class named IllegalRadius, 
                which will contain a double data member called badRadius and a constructor that takes 
                a double and uses it to initialize badRadius.

                6. The static maxRadius data member should be initialized to 10.0

                7. The Circle constructor that takes a parameter should throw an 
                IllegalRadiusException if the parameter exceeds the maxRadius.

*********************************************************************/
# include <iostream>
# include "Circle.hpp"

// Static maxRadius data member should be initialized to 10.0
double Circle::maxRadius = 10.0;


/***********************************
** IllegalRadius exception class
** a constructor that takes a double and 
** uses it to initialize badRadius.
************************************/
Circle::IllegalRadius::IllegalRadius(double badR) {
  this->badRadius = badR;
}

/***********************************
** Default Constructor
** initializes the radius to 1.0. 
************************************/
Circle::Circle() {
  this->radius = 1.0;
}

/***********************************
** Constructor
** takes a double and uses it to initialize the radius.
** throw an IllegalRadiusException if the parameter exceeds the maxRadius.
************************************/
Circle::Circle(double r) {
  this->radius = r;
  if(this->radius > this->maxRadius) {
    throw IllegalRadius(this->radius);
  }
}

/***********************************
** calArea()
** returns the area of the Circle (use 3.14159 for pi).
************************************/
double Circle::calcArea() {
  const double PI = 3.14159;
  return this->radius * this->radius * PI;
}

/***********************************
** setMaxRadius
** set method for the maxRadius
************************************/
void Circle::setMaxRadius(const double maxR) {
  Circle c;
  c.maxRadius = maxR;
}


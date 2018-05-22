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
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle {
  public:
    Circle();
    Circle(double);
    double calcArea();
    static void setMaxRadius(const double);
    class IllegalRadius {
      public:
        double badRadius;
        IllegalRadius(double);
    };
    
  private:
    double radius;
    static double maxRadius;
};

#endif
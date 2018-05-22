/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/21/18
** Description: Main Function:  
                Ask the user to input a value for the maximum 
                radius and sets maxRadius to that value.  
                
                It should then ask the user for a radius, and then create 
                a Circle with that radius.  Next it should print out the 
                area of that Circle.  
                
                Your function should use try/catch to handle the possible exception.  
                If an IllegalRadius exception is thrown, the program should print 
                out an error message as shown below.
*********************************************************************/
#include <iostream>
#include "Circle.hpp"

int main() {
  double maxR;
  double r;

  // Ask the user to input a value for the maximum 
  // radius and sets maxRadius to that value.  

  std::cout << "Enter the maxRadius for Circles." << std::endl;
  std::cin >> maxR;

  // Initializes the maxRadius by calling static setter function
  Circle::setMaxRadius(maxR);

  std::cout << "Enter the radius for a new Circle object." << std::endl;
  std::cin >> r;

  // Ask the user for a radius, and then create a Circle with that radius.
  try {
    Circle c(r);
    std::cout << "The Circle object was successfully created." << std::endl;
    std::cout << "The area of the circle is " << c.calcArea() << "." << std::endl;
  }

  // Handle the possible exception
  // Print out an error message as shown in the example.
  catch(Circle::IllegalRadius e) {
    std::cout << "The Circle object could not be created." << std::endl;
    std::cout << "A radius of " << e.badRadius << " exceeds the maximum allowed radius." << std::endl;
  }

  return 0;  
}
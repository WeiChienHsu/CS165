/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  A function called averageArea that takes as a parameter 
                 a vector of Shape-pointers and returns the average area 
                 of the Shapes.
*********************************************************************/
#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include <vector> 

/***********************************
** averageArea(Shape *)
** takes as a parameter a vector of Shape-pointers and 
** returns the average area of the Shapes.
************************************/
double averageArea(std::vector<Shape*> vec) {
  double total = 0.0;
  double size = vec.size();

  // Take a single instance of Shape and get it's area added into total area
  for(int i = 0; i < size; i++) {
    // Call the area() method in different child class
    total += vec.at(i)->area();
  }
  // Return the average area
  return total / size;
}

int main() {

  Circle c(4.0);
  std::cout << c.area() << std::endl;
  std::cout << c.perimeter() << std::endl;

  Rectangle r(4.0, 8.0);
  std::cout << r.area() << std::endl;
  std::cout << r.perimeter() << std::endl;

  Square s(5.0);
  std::cout << s.area() << std::endl;
  std::cout << s.perimeter() << std::endl;

  std::vector<Shape*> vec;
  vec.push_back(&c);
  vec.push_back(&r);
  vec.push_back(&s);

  std::cout << averageArea(vec) << std::endl;
  
  return 0;
}
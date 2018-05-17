#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

using namespace std;

int main() {

  Circle c(4.0);
  cout << c.area() << endl;
  cout << c.perimeter() << endl;

  Rectangle r(4.0, 8.0);
  cout << r.area() << endl;
  cout << r.perimeter() << endl;

  Square s(5.0);
  cout << s.area() << endl;
  cout << s.perimeter() << endl;
  return 0;
}

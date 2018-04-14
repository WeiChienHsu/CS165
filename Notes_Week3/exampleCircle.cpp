/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Demonstrates a simple class with memner functions
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:
    double radius;
  public:
    Circle();
    void setRadius(double r); // These are prototypes or the member function
    double calcArea();
};

// The member function implemenation secion follows. It contains the 
// acutal function definitions for the Circle class member functions.

/*********************************************************************
**  Constructor : Initialized the redius class member variable.
*********************************************************************/
Circle::Circle() {
  radius = 1.0;
  cout << "This is a constructor!\n";
}

/*********************************************************************
**  Circle :: setRadius
**  This function copies the argument passed into the parameter to
**  the private member variable radius.
*********************************************************************/
void Circle::setRadius(double r) {
  radius = r;
}

/*********************************************************************
**  Circle :: calcArea
**  Calculate the Circle object's area
*********************************************************************/
double Circle::calcArea() {
  return 3.14 * pow(radius, 2);
}
/*********************************************************************
**  Main function
*********************************************************************/
int main() {
  Circle circle1, circle2;
  circle1.setRadius(5);
  circle2.setRadius(10);

  cout << "Circle1 area: " << circle1.calcArea() << endl;
  cout << "Circle2 area: " << circle2.calcArea() << endl;
}
#include <iostream>
#include <cmath>
#include <string>

enum { NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK};

class shape{
  public:
    shape() {
      this->side_count = -1;
      this->color = NOCOLOR;
    }

    shape(int sides) {
      this->side_count = sides;
    }

    virtual double area() {
      if(side_count == -1) {
        return -17;
      } else {
        return 14;
      }
    }

    virtual double perimeter() {
      return 0;
    }

    virtual std::string name() {
      return std::string("SHAPE");
    }

  protected:
    int side_count;
    int color;

};

// Triangle inheritaed shape
class triangle : public shape{
  public:
  // Default Constructor
    triangle() : shape(3) {
      this->side1 = 0;
      this->side2 = 0;
      this->side3 = 0;
    }

    triangle(double side1, double side2, double side3) : shape(3) {
      this->side1 = side1;
      this->side2 = side2;
      this->side3 = side3;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {

      // this->perimeter()
      // Since the this is a pointer to the Instance of Object in this class
      double s = (*this).perimeter() /  2;
      return std::sqrt( s * (s - this->side1) *
                            (s - this->side2) *
                            (s - this->side3)
                      );
    }

    double perimeter() {
      return this->side1 + this->side2 + this->side3;
    }
    
    std::string name() {
      return std::string("TRIANGLE");
    }

  protected:
    double side1;
    double side2;
    double side3;

};

// Rectangle
class rectangle : public shape{
  public:
  // Default Constructor
    rectangle() : shape(4) {
      this->side1 = 0;
      this->side2 = 0;
    }

    rectangle(double side1, double side2) : shape(4) {
      this->side1 = side1;
      this->side2 = side2;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {
      return  this->side1 * this->side2;
    }

    double perimeter() {
      return this->side1 * 2 + this->side2 * 2;
    }

    std::string name() {
      return std::string("RECTANGLE");
    }

  protected:
    double side1;
    double side2;
};

// Square inherited from rectangle

class square : public rectangle{
  // Don't inherit Constructor and Destructor(Which was automacatially be called by compiler when this class ends)
  // Don't inherit private function (Used protected to access private-like function which only for child)

  public:
    square() : rectangle() {
      this->side1 = 0;
      this->side2 = 0;
    }

    square(double side) : rectangle(side, side) {
      this->side1 = side;
      this->side2 = side;
    }

    // Directly call the parent function of area in rectangle

    double area() {
      return rectangle::area();
    }

    double perimeter() {
      return rectangle::perimeter();
    }

    std::string name() {
      return std::string("SQUARE");
    }

  protected:
    
};

void print_area(shape *s, std::string name) {
    std::cout << "Area of " << s->name() << " s (should be " 
              << name << ") : " << s->area() << std::endl;
    std::cout << "Perimeter of " << s->name() <<  " s (should be " 
              << name << ") : " << s->perimeter() << std::endl;
}


int main() {
  shape s;
  triangle t(3,4,5);
  rectangle r(4,5.5);
  square q(10);
  
  print_area(&s, "shape");
  print_area(&t, "triangle");
  print_area(&r, "rectangle");
  print_area(&q, "square");
  return 0;
}
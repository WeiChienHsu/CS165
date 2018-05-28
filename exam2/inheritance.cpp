#include <iostream>
#include <string>
#include <cmath>

class Shape {
  public:

    Shape() {
      this->side_count = -1;
      this->color = "NONCOLOR";
    }

    Shape(int sides, std::string color = "NONCOLOR" ) {
      this->side_count = sides;
      this->color = color;
    }

    virtual double getArea() {
      if(side_count < 0) {
        return -1;
      } else {
        return 10;
      }
    }

    virtual std::string getColor() {
      return this->color;
    }

  protected:
    int side_count;
    std::string color;
};

class Triangle : public Shape {
  public:
    Triangle() : Shape(3) {
      this->side1 = 0;
      this->side2 = 0;
      this->side3 = 0;
    }
    Triangle(double s1, double s2, double s3, std::string color) {
      this->side1 = s1;
      this->side2 = s2;
      this->side3 = s3;
      this->color = color;
    }

    double getArea() {
      double perimeter = this->side1 + this->side2 + this->side3;
      double s = perimeter / 2;
     return std::sqrt( s * (s - this->side1) *
                            (s - this->side2) *
                            (s - this->side3)
                      );
    }

   std::string getColor() {
      return this->color;
    }

  protected:
    double side1;
    double side2;
    double side3;
};

int main() {
  Shape s(4);
  Triangle t(3,4,5,"Blue");
  std::cout << t.getColor() << std::endl;
  std::cout << t.getArea() << std::endl;
  
  return 0;
}
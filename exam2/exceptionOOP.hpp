#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle {
  public:
    Circle(){
      this->radius = 0.0;
    }

    Circle(double r) {
      this->radius = r;
    }

    double calcArea(){
      return this->radius * this->radius * 3.14159;
    }

    static void setMaxRadius(const double maxR) {
        Circle c;
        c.maxRadius = maxR;
    }

    class IllegalRadius {
      public:
        double badRadius;
        IllegalRadius(double r) {
          this->badRadius = r;
        }
    };

    private:
      double radius;
      static double maxRadius;
};

double Circle::maxRadius = 10.0;

#endif
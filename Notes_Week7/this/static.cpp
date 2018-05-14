#include <iostream>

class StatDemo {
  private:
    static int x;
    int y;

  public:
    void setX(int a) {
      this->x = a;
    }

    void setY(int b) {
      this->y = b;
    }

    void print_XY() {
      std::cout<< "X: " << this->x << std::endl;
      std::cout<< "Y: " << this->y << std::endl;
    }

};

int StatDemo::x = 0;

int main() {
  StatDemo a;
  StatDemo b;

  a.setX(100);
  a.setY(5);
  b.setY(10);

  a.print_XY();
  b.print_XY();

  return 0;
}
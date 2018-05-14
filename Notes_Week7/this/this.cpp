#include <iostream>

class Example{
  int x;
  public:
    Example(int a) { x = a; }

    void setValue(int a) {
      x = a;
    }
    void getValueAndObjectAddress() {
      std::cout << "The object at address: " << this << std::endl;
      std::cout << "The value is: " << this->x << std::endl;
    }
};

int main() {
  Example e(5);
  e.getValueAndObjectAddress();
  e.setValue(6);
  e.getValueAndObjectAddress();  
  return 0;
}
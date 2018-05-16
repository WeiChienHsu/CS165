#include <iostream>

class Example {
  private:
    int size;
  public:
    // Convert Constructor with one parameter
    Example(int num) {
      this->size = num;
    }

    int getSize() {
      return this->size;
    }
};

int main() {
  // Normal Assignment
  Example a(10);
  Example c(10);
  
  // Use Convert Constructor
  Example b = 20;
  c = 30;

  std::cout << a.getSize() << std::endl;
  std::cout << b.getSize() << std::endl;
  std::cout << c.getSize() << std::endl;

  return 0;

}
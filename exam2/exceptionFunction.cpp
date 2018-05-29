#include <iostream>

class math_error {};
class divide_by_zero : public math_error {};

void safe_divide(double a, double b) throw (divide_by_zero) {
  if(b == 0) {
    divide_by_zero d;
    throw d;
  }

  std::cout << "Result : " << a / b << std::endl;
}

void calcu(double a, double b) {
  try {
    safe_divide(a, b);
  } catch(divide_by_zero) {
    std::cout << "I shouldn't be divied by 0" << std::endl;
    exit(1);
  } catch(...) {
    std::cout << "Something went wrong but we don't know why" << std::endl;
  }
}

int main() {
  calcu(4, 2);
  calcu(4, 0);
  return 0;
  
}
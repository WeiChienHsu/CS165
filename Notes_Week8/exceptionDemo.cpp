#include <iostream>
#include <string>
#include <stdexcept>

class math_error{};
class divide_by_zero : public math_error{
  public:
    divide_by_zero() {
      std::cout << "Error in the Class" << std::endl;
    }
  
};

double safe_divide(double a, double b) throw (divide_by_zero) {
    if(b == 0) {
      divide_by_zero d;
      throw d;
    }

    std::cout << "I shouldn't see this either." << std::endl;
    
    return a / b;
}

int main() {
  std::string s = "Opps, something bad happened!";

  try {
    safe_divide(4, 0);
    // Skip pass this
    std::cout << "I shouldn't see this" << std::endl;
  }

  catch(divide_by_zero) {
    std::cout << "Attempted to divided by ZERO" << std::endl;
    exit(-1);
  }

  // Parent Class won't be called if you put it away from try
  catch(math_error) {
    std::cout << "Attempted to event new MATH" << std::endl;
    exit(-1);
  }

  catch(...) {
    std::cout << "Something went wrong but we don't know why!" << std::endl;
  }


  return 0;
}
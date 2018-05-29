#include <iostream>
#include <string>

int main() {
  std::string s = "Opps, something bad happened!";

  try {
    // throw s;
    throw 10;

    // Skip pass this
    std::cout << "I shouldn't see this" << std::endl;
  }
  catch(int e) {
    std::cout << "An exception occurred. Exception number: " << e << std::endl;
  }

  catch(std::string e) {
    std::cout << e << std::endl;
  }

  catch(...) {
    std::cout << "Something went wrong but we don't know why!" << std::cout;
  }

  return 0;
}
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(10);
  try {
    std::cout << v.at(15) << std::endl;  
  }
  catch(std::out_of_range e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
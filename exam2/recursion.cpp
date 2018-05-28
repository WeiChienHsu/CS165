#include <iostream>

int factorial(int num) {
  if(num == 1){
    std::cout << "1 = ";
    return 1;
  } 
  std::cout << num << " * ";
  return num * factorial(num - 1);
}

int main() {
  std::cout << factorial(10) << std::endl;
  return 0;
}
#include <iostream>
#include <string>

int main() {
  std::string faveAnimal;
  std::cout << "Please enter your favorite animal." << std::endl;
  std::cin >> faveAnimal;
  std::cout << "Your favorite animal is the " << faveAnimal << std::endl;
  return 0;
}
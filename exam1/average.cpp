#include <iostream>

int main() {

  double const INPUT_NUMBER = 5.0;  
  double totalNumber = 0;
  double inputNumber;
  std::cout << "Please enter " << INPUT_NUMBER << " number. \n";
  
  for(int i = 0; i < INPUT_NUMBER; i++) {
    std::cin >> inputNumber;
    totalNumber += inputNumber;
    std::cout << "Your input: " << inputNumber << std::endl;
  }

  std::cout << "The average of those numbers is: " << std::endl;
  std::cout << totalNumber / INPUT_NUMBER << std::endl;
  return 0;
}
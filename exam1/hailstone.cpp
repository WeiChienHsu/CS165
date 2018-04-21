#include <iostream>

int main() {
  int len = 0, currentNum;
  std::cout << "input number: " << std::endl;
  std::cin >> currentNum;

  while(currentNum != 1) {
    if(currentNum % 2 == 0) {
      currentNum /= 2;
    } else {
      currentNum = currentNum * 3 + 1;
    }
    len++;
  }

  std::cout << len << std::endl;
  return 0;
}
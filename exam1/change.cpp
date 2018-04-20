#include <iostream>

int main() {
  int number, q = 0, d = 0, n = 0, p = 0;
  std::cout << "Please enter an amount in cents less than a dollar." << std::endl;
  std::cin >> number;

  if(number >= 25) {
    q = number / 25;
    number %= 25;
  }

  if(number >= 10) {
    d = number / 10;
    number %= 10;
  }

  if(number >= 5) {
    n = number / 5;
    number %= 5;
  }

  p = number;

  std::cout << "Your change will be:" << std::endl;
  std::cout << "Q: " << q << std::endl;
  std::cout << "D: " << d << std::endl;
  std::cout << "N: " << n << std::endl;
  std::cout << "P: " << p << std::endl;

  return 0;
}
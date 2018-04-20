#include <iostream>
int main() {
  int numberOfIntegers, num, maxValue, minValue;

  std::cout << "How many integers would you like to enter?" << std::endl;
  std::cin >> numberOfIntegers;
  std::cout << "Please enter " << numberOfIntegers << " integers." << std::endl;
  std::cin >> num;
  maxValue = num;
  minValue = num;
  numberOfIntegers--;

  while(numberOfIntegers > 0) {
    std::cin >> num;
    if(num < minValue) {
      minValue = num;
    }

    if(num > maxValue) {
      maxValue = num;
    }
    numberOfIntegers--;
  }

  std::cout << "min: " << minValue << std::endl;
  std::cout << "max: " << maxValue << std::endl;

  return 0;
}
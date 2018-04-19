#include <iostream>
#define ELE 5

int main() {
  int arr[ELE];

  std::cout << "Array Locatoin : " << arr << std::endl;
  std::cout << "Array Pointer Location : " << &arr << std::endl;
  std::cout << "Array Default Value : " << arr[0] << std::endl;

  for(int i = 0; i < 100000; i++) {
    arr.at(i) = i;
    std::cout << "Current Value: " << arr[i] << std::endl;
  }
  return 0;
}
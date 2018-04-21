#include <iostream>
#include "Box.hpp"

int main() {
  Box box(10, 15, 5);
  std::cout << "Volume: " << box.calcVolume() << std::endl;
  std::cout << "SurfaceArea: " << box.calcSurfaceArea() << std::endl;

  return 0;
}
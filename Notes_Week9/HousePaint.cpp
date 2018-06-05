#include <iostream>
#include "HousePaint.hpp"

HousePaint::HousePaint(Color sColor, Color tColor) {
  setSiding(sColor);
  setTrim(tColor);
}

void HousePaint::setSiding(Color sColor) {
  this->siding = sColor;
}

Color HousePaint::getSiding() {
  return this->siding;
}

void HousePaint::setTrim(Color tColor) {
  this->trim = tColor;
}

Color HousePaint::getTrim() {
  return this->trim;
}

int main() {
  HousePaint hp(maroon, ivory);
  if(hp.getTrim() == ivory) {
    std::cout << hp.getTrim() << std::endl;
  }
}
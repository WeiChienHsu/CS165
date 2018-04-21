#include <iostream>
#include "Box.hpp"

Box::Box() {
  setHeight(0);
  setWidth(0);
  setLength(0);
}

Box::Box(int h, int w, int l) {
  setHeight(h);
  setWidth(w);
  setLength(l);
}

void Box::setHeight(int h) {
  height = h;
}

void Box::setWidth(int w) {
  width = w;
}

void Box::setLength(int l) {
  length = l;
}

int Box::calcVolume() {
  return height * width * length;
}

int Box::calcSurfaceArea() {
  return 2 * ((height * width) + (width * length) + (length * height));
}

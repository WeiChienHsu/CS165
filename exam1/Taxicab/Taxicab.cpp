#include <iostream>
#include "Taxicab.hpp"

Taxicab::Taxicab() {
  coordX = 0;
  coordY = 0;
}

Taxicab::Taxicab(int x, int y) {
  coordX = x;
  coordY = y;
}

void Taxicab::moveX(int x) {
  coordX += x;
  if(x > 0) {
    totalDistance += x;
  } else {
    totalDistance -= x;
  }
}

void Taxicab::moveY(int y) {
  coordY += y;
  if(y > 0) {
    totalDistance += y;
  } else {
    totalDistance -= y;
  }
}

int Taxicab::getDistanceTraveled() {
  return totalDistance;
}

int Taxicab::getXCoord() {
  return coordX;
}

int Taxicab::getYCoord() {
  return coordY;
}
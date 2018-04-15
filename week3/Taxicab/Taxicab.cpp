/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The function definitions (implementation) for Taxicab.              
                 Private Values: 3 int fields called xCoord, yCoord and totalDistance.

                 (has three int fields (data members) to store its current x- and 
                  y-coordinates and the total distance it has driven so far)
                 
                 Implementaion:
                  - Taxicab(): a default constructor that sets all three fields to zero.
                  - Taxicab(int x, int y): a constructor that takes two parameters and 
                  uses them to initialize the coordinates, and also initializes the 
                  distance traveled to zero.
                  - Three Getter functions: getXCoord(), getYCoord() and getDistanceTraveled() 
                                            to return their value.
                  - moveX():  takes an int parameter that tells how far the Taxicab should 
                              shift left or right.
                  - moveY():  takes an int parameter that tells how far the Taxicab should 
                              shift up or down
*********************************************************************/

#include <iostream>
#include "Taxicab.hpp"
using namespace std;

Taxicab::Taxicab() {
  xCoord = 0; yCoord = 0; totalDistance = 0;
}

Taxicab::Taxicab(int x, int y) {
  xCoord = x;
  yCoord = y;
  totalDistance = 0;
}

int Taxicab::getXCoord() {
  return xCoord;
}

int Taxicab::getYCoord() {
  return yCoord;
}

int Taxicab::getDistanceTraveled() {
  return totalDistance;
}

void Taxicab::moveX(int x) {
  xCoord += x;
  if(x > 0) {
    totalDistance += x;
  } else {
    totalDistance -= x;
  }
}

void Taxicab::moveY(int y) {
  yCoord += y;
  if(y > 0) {
    totalDistance += y;
  } else {
    totalDistance -= y;
  }
}

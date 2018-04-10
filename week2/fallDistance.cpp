/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Write a function named fallDistance that takes the 
                 falling time as an argument.

                 The function should return the distance in meters 
                 that the object has fallen in that time.

                 d\:=\:\frac{1}{2}gt^2

                 d is the distance in meters.
                 g is 9.8.
                 t is the time in seconds that the object has been falling
*********************************************************************/

#include <iostream>
using namespace std;

// Function returns the distance in float

float fallDistance(float fallingTime) {
  float distance;
  const float G = 9.8;

  distance = (G * fallingTime * fallingTime ) / 2;
  return distance;
}

// int main() {
//   float distance, fallingTime;

//   cin >> fallingTime;
//   distance = fallDistance(fallingTime);

//   cout << "The distance is: " << distance << endl;
//   return 0;
// }


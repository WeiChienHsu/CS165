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

// Function returns the distance in double

double fallDistance(double fallingTime) {
  double distance;
  const double G = 9.8;

  distance = (G * fallingTime * fallingTime ) / 2;
  return distance;
}

// int main() {
//   double distance, fallingTime;

//   std::cin >> fallingTime;
//   distance = fallDistance(fallingTime);

//   std::cout << "The distance is: " << distance << std::endl;
//   return 0;
// }


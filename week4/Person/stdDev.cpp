/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/24/18
** Description:  stdDev function that takes two parameters 
                  - an array of Person objects and the size of the array 
                  and returns the standard deviation of all the ages.

                  (the population standard deviation that uses a denominator 
                  of N, not the sample standard deviation, which uses a 
                  different denominator).  

*********************************************************************/
#include <iostream>
#include "Person.hpp"
#include <math.h>       /* sqrt */

/***********************************
** stdDev(Person *arr, int size)
** returns the standard deviation of all the ages.
************************************/

double setDev(Person *arr, int size) {
  double sum, mean, squareResult, answer;
  
  // Work out the Mean
  for(int i = 0; i < size; i++) {
    sum += arr[i].getAge();
  }

  mean = sum / size;

  // Then for each number: subtract the Mean and square the result
  for(int i = 0; i < size; i++) {
    double subtract = mean - arr[i].getAge();
    squareResult += (subtract * subtract);
  }

  // Work out the mean of those squared differences.
  // Take the square root of that
  answer = sqrt(squareResult / size);
  return answer;
}


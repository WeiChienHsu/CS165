/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/02/18
** Description: a recursive function named summer that takes two parameters - 
                an array of doubles and the size of the array - and returns the 
                sum of the values in the array.  The size parameter does not have 
                to be the actual size of the array.  It will be at the top level, 
                but at the lower recursive levels it can be the size of the sub-array 
                being worked on at that level.

** Example    :  {1.0, 1.5, 10.0}; -> Return :12.5
*********************************************************************/
#include <iostream>

/*************************************************************
 *  Functions prototype
**************************************************************/
double summer(double arr[], int size);

/*************************************************************
** double summer(double arr[], int size)
** Base Cass is when size meets zero, just return 0
** In each level, we count the current value add the rest of 
** then puttin into the next level of recursive function.
** Ex.
** arr[] = {1, 2, 3}
** summer(arr, 3) = 3 + summer(arr, 2) = 3 + 2 + summer(arr, 1)
** = 3 + 2 + 1 + summer(arr, 0) = 3 + 2 + 1 + 0 = 6
**************************************************************/

double summer(double arr[], int size) {
  if(size == 0) return 0;
  return arr[size - 1] + summer(arr, size - 1);
}


// int main() {
//   double arr[] = {1.0, 1.5, 10.0};
//   std::cout << summer(arr, 3) << std::endl;
//   return 0;
// }
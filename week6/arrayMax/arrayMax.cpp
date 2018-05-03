/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/02/18
** Description: a recursive function named arrayMax that takes as 
                parameters an array of ints and the size of the array 
                and returns the maximum value in the array.

** Example    :  {2,2,4,10,22,34,1,33,35,3}; -> Return :35
                 {-2,-2,-4,-10,-22,-34,-1,-33,-35,-3}; -> Return : -1
                 {5,5,5,5}; -> Return :5
*********************************************************************/

#include <iostream>

/*************************************************************
 *  Functions prototype
**************************************************************/
int arrayMax(int arr[], int size);

/*************************************************************
** arrayMax(int arr[], int size)
** Check two value in each level. 
** If current value is larger than privious value, return current value
** If current value is smaller or equal to previous value, put that index
** into the next level to compare with it's prevous value
** If we meet the basic casee which means current index equal to 0,
** we just need to return the current value, since the conditional 
** expression above will help us to handle the comparasion.
**************************************************************/


int arrayMax(int arr[], int size) {
  if(size == 0) return arr[0];

  if(arr[size - 1] > arrayMax(arr, size - 1)) {
    return arr[size - 1];
  } else {
    return arrayMax(arr, size - 1);
  }
}

// int main() {
//   int arr[] = {2,2,4,10,22,34,1,33,35,3};
//   std::cout << arrayMax(arr, 10) << std::endl;
//   return 0;
// }
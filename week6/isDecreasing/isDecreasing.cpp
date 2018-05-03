/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/02/18
** Description: a recursive function named isDecreasing that takes as parameters 
                an array of ints and the size of the array.  It should return true 
                if the elements of the array are strictly decreasing (each element 
                in the array is strictly less than the previous one), but return 
                false otherwise.

** Example    :  {1,2,3,4,5}; -> Return :false
                 {5,4,3,2,1}; -> Return :true
                 {5,4,4,3,2}; -> Return :false
*********************************************************************/

#include <iostream>

/*************************************************************
 *  Functions prototype
**************************************************************/
bool isDecreasing(int arr[], int size);

/*************************************************************
** isDecreasing(int arr[], int size)
** Recursive function that will receive the last number in the array,
** and it will check if that value is strictly larger than the previous
** one.
**************************************************************/


bool isDecreasing(int arr[], int size) {

    // Out of the arr boundary
    if(size <= 0) {
      return true;
    } else if(arr[size] >= arr[size - 1]) {
      // Previous value is equal or larger than current value
      return false;
    } else {
      // Current Level don't have any problem
      // Check the next level
      return isDecreasing(arr, size - 1);
    }
}

// int main() {
//   int arr[]  = {1,2,3,4,5};
//   int arr2[] = {5,4,3,2,1};
//   int arr3[] = {5,4,4,3,2};
//   std::cout << isDecreasing(arr, 5) << std::endl;
//   std::cout << isDecreasing(arr2, 5) << std::endl;
//   std::cout << isDecreasing(arr3, 5) << std::endl;

//   return 0;
// }
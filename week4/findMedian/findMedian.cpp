/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/24/18
** Description:  The function takes an array of int and the size of the array
                 and then return the median of the array.

** Remind:       It's different for odd and even groups of values.  
                 If you are testing your code by calling it from a main function 
                 in a different file, remember to have a function prototype for 
                 findMedian in that file.            
*********************************************************************/

#include <iostream>

/*********************************************************************
**  BubbleSort(int *A, int size)
**  This function takes two parameters - (an array of int and the size of the array.)
**  The function will check if the privious number is smaller than the next one.
**  If the privous number is greater, it will switch it with the targeted one to 
**  make sure we have an Increment ordered Array.
*********************************************************************/

void BubbleSort(int *A, int size) {
  int i, j, temp;
  for(i = 0; i < size; i++){
    for(j = 0; j < size - 1; j++) {
      if(A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
}

/*********************************************************************
**  findMedian(int[] arr, int size)
**  This function takes two parameters - (an array of int and the size of the array.)
**  The function should return the median of the array.
**  This function will change the original array.
*********************************************************************/

double findMedian(int *arr, int size) {

  // Sort the original array
  // We let the pointer in fuction points to the original array
  // Change the value inside the array
  BubbleSort(arr, size);

  // Take the mediam out from the array
  // If size is an odd number, take the number in the index of (size / 2)
  if(size % 2 != 0) {
    int mediamIndex = (size / 2);
    return arr[mediamIndex] * 1.0;

  // If size is a even number, mediam equal to (arr[size/2] + arr[size/2 - 1]) / 2
  } else {
    int mediamIndex = (size / 2);
    return (arr[mediamIndex] + arr[mediamIndex - 1]) / 2.0;
  }
}


// int main() {
//   int array[] = {1,5,7,4,2,6,3,9,8};
//   double result = findMedian(array, 9);
//   std::cout << result << std::endl;
//   return 0;
// }
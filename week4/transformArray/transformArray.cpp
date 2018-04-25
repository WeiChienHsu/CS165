/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/24/18
** Description:  a void function called transformArray that takes two parameters - 
                  a reference to a pointer to a dynamically allocated array of ints, 
                  and the size of that array.  

                  The pointer is passed by reference because you want to change the 
                  value of the pointer. The function should replace the array with 
                  one that is twice as long, with the values from the original array 
                  followed by each of those values plus one. 

** Example:       If array that was passed in was {4, 2, 5}, then it should be 
                  replaced by {4, 2, 5, 5, 3, 6}.  The function should prevent 
                  any memory leaks.  Remember to also prevent memory leaks in the 
                  main you use for testing.

*********************************************************************/
#include <iostream>

/*********************************************************************
** transformArray(int* arr, int size)
** It could prevent the memory Leaks since the Pointers still point to
** the first address of this new Array which used the same address of
** our old Array.
*********************************************************************/

void transformArray(int* arr, int size) {
  int newSize = size * 2;
  int tempArray[newSize];

  // Copy the value of the Old Array into the temp Array in the Stack
  for(int i = 0; i < newSize; i++) {
    if(i < size) {
      tempArray[i] = arr[i];
    } else {
      tempArray[i] = arr[i - size] + 1;
    }
  }

  // New a Array[size * 2] in the Heap and let the pointer still points to the New Array
  // Assign the Value by temp Array
  for(int i = 0; i < newSize; i++) {
    arr[i] = tempArray[i];
  }


  // Directly Assign new Value to the rest of new Array by 
  // calling pointer points to the next Address in Heap

  // for(int i = 0; i < newSize; i++) {
  //   if(i < size) {
  //     continue;
  //   } else {
  //     arr[i] = arr[i - size] + 1;
  //   }
  // }
}

// int main() {
//   int* myArray = new int[3];
//   myArray[0] = 4;
//   myArray[1] = 2;
//   myArray[2] = 5;

//   transformArray(myArray, 3);
  
//   for (int i=0; i<6; i++)
//     std::cout << myArray[i] << std::endl;

//   delete []myArray;

//   return 0;
// }
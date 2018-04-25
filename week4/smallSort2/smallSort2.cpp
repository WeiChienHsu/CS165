/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/24/18
** Description:   a void function named smallSort2 that takes as parameters 
                  the addresses of three int variables and sorts the ints at 
                  those addresses into ascending order. 
*********************************************************************/
#include <iostream>

/*********************************************************************
** swap(int* large, int* small)  function 
** Take the addresses of two int variables(which are stored in the Pointers 
  in smallSort2 funciton) and swap two number in their Address. 
*********************************************************************/
void swap(int* large, int* small) {
  int temp = *small;
  *small = *large;
  *large = temp;
}

/*********************************************************************
** smallSort2(int* ptr1, int* ptr2, int* prt3)
** Take the addresses of three int variables and sorts the ints "at those 
   addresses" into ascending order. 
*********************************************************************/
void smallSort2(int* ptrFirst, int* ptrSecond, int* ptrThird) {
  
  // Make sure the First one is the smallest
  if(*ptrFirst > *ptrSecond) {
    swap(ptrFirst, ptrSecond);
  }

  if(*ptrFirst > *ptrThird) {
    swap(ptrFirst, ptrThird);
  }

  // Make sure the second one is not greater than third one
  if(*ptrSecond > *ptrThird) {
    swap(ptrSecond, ptrThird);
  }
}

// int main() {
//   int first = 14;
//   int second = -90;
//   int third = 2;
//   smallSort2(&first, &second, &third);
//   std::cout << first << ", " << second << ", " << third << std::endl;
//   return 0;
// }
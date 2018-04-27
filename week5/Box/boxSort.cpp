/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description: Modify the bubble sort function to Sorts an array of Boxes 
                from greatest volume to least volume.
                Function boxSort() should take two parameters: an array of 
                Boxes, and the size of the array.
*********************************************************************/
#include <iostream>
#include "Box.hpp"

/******************************************
** swapBox()
** Take the box array and index of two boxes
** which need to be switched.
*******************************************/
void swapBox(Box *arr, int i, int j) {
  Box tempBox = arr[i];
  arr[i] = arr[j];
  arr[j] = tempBox;
}


/****************************************************
** boxSort()
** Implement by a BubbleSort to sort the boxes
** in Box Array.
** Make sure the last one is the one with least volume.
*****************************************************/
void boxSort(Box *arr, int size) {
  for(int currentLast = size - 1; currentLast >= 0; currentLast--) {
    for(int j = 0; j < currentLast; j++) {
      if(arr[j].calcVolume() < arr[j + 1].calcVolume()) {
        swapBox(arr, j, j + 1);
      }
    }
  } 
}

int main() {
  int size = 5;
  Box box1(2,2,2);
  Box box2(3,3,3);
  Box box3(1,1,1);
  Box box4(3,1,1);
  Box box5(1,5,5);

  Box arr[] = {box1, box2, box3, box4, box5};
  boxSort(arr, size);

  for(int i = 0; i < size; i++) {
    std::cout << arr[i].calcVolume() << std::endl;
  }
  return 0;
}
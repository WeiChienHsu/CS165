/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  Modify the selection sort function to sort an array of 
                 C++ strings (std::string) into dictionary order. 

                 The function take two parameters, an array of strings, 
                 and the size of the array.  

                 This sort should be case-insensitive, so that "zebra" 
                 would come before "Zeppelin".The case-insensitivity 
                 should be for the whole string, not just the first letter. 
                 (Compare them without changing their value - pass by Value)

                 We will make our own string comparison function that uses 
                 toupper() together with the built-in string comparison 
                 ('<' or '>'), but don't change the original strings.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype> // For the toupper function


void swap(std::string arr[], int i, int j);
bool isSmallerThanCurrent(std::string arr[], int currentIndex, int previousIndex);
int findMinIndex(std::string arr[], int size, int currentIndex);

/***********************************
** isSmallerThanCurrent(std::string *arr, int currentIndex, int previousIndex)
** The function take three parameters, an array of strings, 
** currentIndex and prevousIndex.  
** This function will Compare two string from current Index
** and previous one after changing to upper case to see 
** "if prevous string is smaller than the current one"
** Ex. arr[currintInedx] = aBd
**     arr[prevousIndex] = abc
** -> ABC < ABD -> C < D -> return true 
********************************************/

bool isSmallerThanCurrent(std::string arr[], int currentIndex, int previousIndex) {
  // Make sure we choose the shorter string 
  // If there is a situation we got "abc" and "abcd",
  // We will see abc as a smaller one and just go through the first three charactor
  int curLength = arr[currentIndex].length();
  int prevLength = arr[previousIndex].length();
  int len;
  if(curLength < prevLength) {
    len = curLength;
  } else {
    len = prevLength;
  }

  // Compare the string by checking through each charactors:
  // if curChar == prevChar : contiue
  // if curChar > prevChar : return True
  // if curChar < prevChar : return False

  for(int i = 0; i < len; i++) {
    char curChar = toupper(arr[currentIndex][i]); 
    char prevChar = toupper(arr[previousIndex][i]);
    if(curChar == prevChar) {
      continue;
    } else if(curChar > prevChar) {
      return true;
      
    } else {
      return false;
    }
  }
  // After checking whole string, we still couldn't figure out the order
  // Return Ture if previous string is the shorter one, since the longer
  // one will have the Larger value in this case;
  return prevLength == len;
}

/***********************************
** int findMinIndex(std::string *arr, int size, int currentInedx)
** The function take three parameters, an array of strings, 
** the size of the array and the current Index. 
** Since in the selectSort, we need to keep finding the index
** of String Array which include the smallest number, so we
** use this method to return the minIndex
********************************************/
int findMinIndex(std::string arr[], int size, int currentIndex) {
  // Init the minIndex to the current Index
  int minIndex = currentIndex;
  for(int i = currentIndex + 1; i < size; i++) {
    // If Current MinIndex String is not the smallest, change the minIndex
    if(isSmallerThanCurrent(arr, minIndex, i)) {
      minIndex = i;
    }
  }
  return minIndex;
}

/***********************************
** swap(std::string *arr, int i, int j)
** The function take three parameters, an array of strings, 
** the indexs in array that we need to change the position.
********************************************/
void swap(std::string arr[], int i, int j) {
  std::string tempString = arr[i];
  arr[i] = arr[j];
  arr[j] = tempString;
}

/***********************************
** stringSort(std::string *arr, int size)
** The function take two parameters, an array of strings, 
** and the size of the array.  
** This function will sort an array of strings
** into dictionary order. 
********************************************/

void stringSort(std::string *arr, int size) {
  // Keep the current index have the smallest string
  for(int i = 0; i < size; i++) {
    int minIndex = findMinIndex(arr, size, i);
    swap(arr, i, minIndex);
  }
}


// int main() {
//   const int SIZE = 4;
//   std::string str1 = "zebra";
//   std::string str2 = "Apple";
//   std::string str3 = "Zeppelin";
//   std::string str4 = "CcCcCcCcCC";
//   std::string strList[SIZE] = {str1, str2, str3, str4};

//   stringSort(strList, SIZE);

//   for(int i = 0; i < SIZE; i++) {
//     std::cout << strList[i] << std::endl;
//   }

//   return 0;
// }
/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/26/18
** Description:  Modify the binary search function takes two parameters: 
                 a const vector of Persons  and the name of the Person 
                 being searched for. If the Person object with the matching 
                 name is found in the vector, the index of its position 
                 should be returned.  Otherwise it should return -1.

** Remind:      The vector of Persons is being passed by const 
*********************************************************************/

#include <iostream>
#include <vector>
#include <cctype> // For the toupper function
#include "Person.hpp"

/*************************************************************
** bool smallerThanTarger(std::string curString, std::string target))
** In order to get the right middle point in the Binary Search,
** we need to compare the target with current string, if current 
** string(current middle string) is smaller than target, return True.
**************************************************************/

bool smallerThanTarger(std::string curString, std::string target) {
  // Make sure we choose the shorter string 
  // If there is a situation we got "abc" and "abcd",
  // We will see abc as a smaller one and just go through the first three charactor
  int curLength = curString.length();
  int tarLength = target.length();
  int len;
  if(curLength < tarLength) {
    len = curLength;
  } else {
    len = tarLength;
  }

  // Compare the string by checking through each charactors:
  // if curChar == tarChar : contiue
  // if curChar < tarChar : return True
  // if curChar > tarChar : return False

  for(int i = 0; i < len; i++) {
    char curChar = toupper(curString[i]); 
    char tarChar = toupper(target[i]);
    if(curChar == tarChar) {
      continue;
    } else if(curChar < tarChar) {
      return true;
    } else {
      return false;
    }
  }
  // After checking whole string, we still couldn't figure out the order
  // Return Ture if previous string is the shorter one, since the longer
  // one will have the Larger value in this case;
  return curLength == len;
}

/*************************************************************
** personSearch(const std::vector<Person> &vec, double target)
** Takes two parameters: a const vector of Persons (which will
** already be sorted by name), and the name of the Person being 
** searched for.
**  If the Person object with the matching name is found in the 
** vector, the index of its position should be returned.  
** Otherwise it should return -1.
**************************************************************/
int personSearch(const std::vector<Person> &vec, std::string target) {
  int start = 0;
  int end = vec.size() - 1;
  // Implement the Binary Search
  // If Name in the middle is <= target, set the new start point in that middle point
  // If Name in the middle is > target, set the new end point the that middle point
  // To avoid the corner case(Duplicate People in the vector), we use start + 1 < end 
  // to let start and end pointers stay in different number

  while(start + 1 < end) {
    int middle = start + (end - start) / 2;
    if(vec.at(middle).getName() == target) {
      start = middle;
    } else if(smallerThanTarger(vec.at(middle).getName(), target)) {
      start = middle;
    } else {
      end = middle;
    }
  }

  // To check which point is the answer
  if(vec.at(start).getName() == target) {
    return start;
  }

  if(vec.at(end).getName() == target) {
    return end;
  }

  // Target String doesn't exist in vector
  return -1;
}

// int main() {
//   std::vector<Person> vec;
//   Person p1 = Person("Kevin", 22);
//   Person p2 = Person("Peter", 33);
//   Person p3 = Person("Kids", 10);

//   vec.push_back(p1);
//   vec.push_back(p2);
//   vec.push_back(p3);

//   const std::vector<Person> vec2(vec);


//   std::cout << "Find Kevin in vector: " << personSearch(vec2, "AA") << std::endl;
//   return 0;
// }
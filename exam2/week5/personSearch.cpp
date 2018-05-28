#include "Person.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For the toupper function


bool smallerThanTarget(std::string curString, std::string target) {

  int curLength = curString.length();
  int tarLength = target.length();

  int len;
  if(curLength < tarLength) {
    len = curLength;
  } else {
    len = tarLength;
  }

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

  return curLength == len;
}


int binarySearch(const std::vector<Person> vec, std::string target) {
  int size = vec.size();
  int start = 0;
  int end = size - 1;
  
  while(start + 1 < end) {
    int middle = start + (end - start) / 2;
    if(vec.at(middle).getName() == target) {
      start = middle;
    } else if(smallerThanTarget(vec.at(middle).getName(), target)) {
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

void personSearch(const std::vector<Person> vec, std::string target) {
  int targetPosition = binarySearch(vec, target);
  if(targetPosition >= 0) {
    std::cout << target << " is in the vector, age: " << vec.at(targetPosition).getAge() << std::endl;
  } else {
    std::cout << target << " is NOT in the vector." << std::endl;
  }
}


int main() {
  Person a("Kevin", 20);
  Person b("Joe", 30);
  Person c("James", 40);
  Person d("Peter", 10);
  std::vector<Person> vec;
  vec.push_back(c);
  vec.push_back(b);
  vec.push_back(a);
  vec.push_back(d);
  personSearch(vec, "Joe");
  personSearch(vec, "Kevin");
  personSearch(vec, "Reaeer");
  return 0;
}
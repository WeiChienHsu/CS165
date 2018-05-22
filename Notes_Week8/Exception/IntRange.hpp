#ifndef INTRANGE_HPP
#define INTRANGE_HPP

#include <iostream>
using namespace std;

class IntRange {
  private:
    int input; // For user input
    int lower; // Lower limit of range
    int upper; // Upper limit of range
  
  public:
    // Exception class
    class OutOfRange {
      public:
        int value;
        OutOfRange(int);
    };
    // Member function
    IntRange(int, int);
    int getInput();  
};

#endif
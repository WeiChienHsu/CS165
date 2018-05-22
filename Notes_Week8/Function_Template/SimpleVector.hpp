#ifndef SIMPLEVECTOR_HPP
#define SIMPLEVECTOR_HPP

#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

// Exception for index out of range
struct IndexOutOfRange {
  const int index;
  IndexOutOfRange(int ix) : index(ix) { }
};

template <class T>
class SimpleVector {
  private:
    T *aptr;
    int arraySize;
  public:
    SimpleVector(int);
    SimpleVector(const SimpleVector &);
    ~SimpleVector();
    int size() const { return arraySize;}
    T &operator[](int); // Overload [] operator
    void print() const; // Outputs the array elements
};

#endif
#ifndef SEARCHABLEVECTOR_HPP
#define SEARCHABLEVECTOR_HPP
#include <iostream>
#include <cstdlib>
#include <memory>
#include "SimpleVector.hpp"

using namespace std;

template <class T>
class SearchableVector : public SimpleVector<T> {
  public:
    // Constructor
    SearchableVector(int);
    // Copy Constructor
    SearchableVector(const SearchableVector &);
    ~SearchableVector();
    // Additional Constructor
    SearchableVector(const SimpleVector<T> &);
    int findItem(T);
};

#endif
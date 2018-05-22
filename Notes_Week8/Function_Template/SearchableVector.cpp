#include <iostream>
#include <cstdlib>
#include <memory>
#include "SearchableVector.hpp"

using namespace std;

/**************************************
** Constructor
****************************************/
template <class T>
SearchableVector<T>::SearchableVector(int s) : SimpleVector<T>(s) {
  // Only need to call the constructor of SimpleVector
}

/**************************************
** Copy Constructor
****************************************/
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector<T> &obj) : SimpleVector<T>(obj) {
  // Only need to call the constructor of SimpleVector
}

/**************************************
** Additional Constructor
****************************************/
template <class T>
SearchableVector<T>::SearchableVector(const SimpleVector<T> &obj) : SimpleVector<T>(obj) {

}

// template <class T>
// SearchableVector<T>::~SearchableVector() : SimpleVector<T>::~SimpleVector() {
// }


/**************************************
** findItem
****************************************/
template <class T>
int SearchableVector<T>::findItem(T item) {
  for(int i = 0; i < this->arraySize; i++) {
    if(this->operator[](i) == item) {
      return i;
    }
  }
  return -1;
}

int main() {
  const int SIZE = 10;
  SearchableVector<int> intTable(SIZE);
  SearchableVector<double> doubleTalbe(SIZE);

  // Store Values in the array

  // for(int i = 0; i < SIZE; i++) {
  //   intTable[i] = (i * 2);
  //   doubleTalbe[i] = (i *2.14);
  // }  

  // // DIsplay the value in the arrays
  // cout << "Int Table:" << endl;
  // intTable.print();
  // cout << "Double Talbe:" << endl;
  // doubleTalbe.print();


  // // Use the build-in + operator on array elements
  // for(int i = 0; i < SIZE; i++) {
  //   intTable[i] += 5;
  //   doubleTalbe[i] += 2.0;
  // }  

  // // DIsplay the value in the arrays
  // cout << "Int Table:" << endl;
  // intTable.print();
  // cout << "Double Talbe:" << endl;
  // doubleTalbe.print();
    
  return 0;
}
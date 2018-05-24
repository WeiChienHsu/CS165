#include <iostream>
#include <cstdlib>
#include <memory>
#include "SimpleVector.hpp"
using namespace std;

/**************************************
** Constructor for SimpleVector class.
** Set the size of the array and 
** allocates memory for it
****************************************/
template <class T>
SimpleVector<T>::SimpleVector(int s) {
  this->arraySize = s;
  this->aptr = new T[this->arraySize];
}

/**************************************
** Copy Constructor
****************************************/
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
  this->arraySize = obj.arraySize;
  this->aptr = new T[this->arraySize];
  for(int count = 0; count < this->arraySize; count++) {
    this->aptr[count] = obj[count];
  }
}

/**************************************
** Destructor: deallocates the dynamically allocated array
****************************************/
template <class T>
SimpleVector<T>::~SimpleVector() {
  delete []aptr; 
}





/**************************************
** Overload [] operator.
** The argument is a subscript.
** This function returns a reference to the element
** in the array indexed by subscript
****************************************/
template <class T>
T &SimpleVector<T>::operator[](int sub) {
  if(sub < 0 || sub >= this->arraySize) {
    throw IndexOutOfRange(sub);
  }
  return this->aptr[sub];
}

/**************************************
** Print a;; tje entries is the array
****************************************/
template <class T>
void SimpleVector<T>::print() const {
  for(int i = 0; i < this->arraySize; i++) {
    cout << this->aptr[i] << " " ;
  }
  cout << endl;
}


/***********************************
** Operator Overloading
** each of the two objects involved has its own 
** separate copy of the memory that its own pInteger points to.  
** The =operator should return a reference to the object 
** pointed to by the this pointer. 
************************************/

// MyInteger& MyInteger::operator=(const MyInteger &right) {
//   // Delete the memory stored the original pointer pointed to
//   delete[] pInteger;

//   pInteger = new int;
//   // Assign the value of right pointer pointed to for pointer in current class
//   *pInteger = *(right.pInteger);
//   return *this;
// }


int main() {
  const int SIZE = 10;
  SimpleVector<int> intTable(SIZE);
  SimpleVector<double> doubleTalbe(SIZE);

  // Store Values in the array

  for(int i = 0; i < SIZE; i++) {
    intTable[i] = (i * 2);
    doubleTalbe[i] = (i *2.14);
  }  

  // DIsplay the value in the arrays
  cout << "Int Table:" << endl;
  intTable.print();
  cout << "Double Talbe:" << endl;
  doubleTalbe.print();


  // Use the build-in + operator on array elements
  for(int i = 0; i < SIZE; i++) {
    intTable[i] += 5;
    doubleTalbe[i] += 2.0;
  }  

  // DIsplay the value in the arrays
  cout << "Int Table:" << endl;
  intTable.print();
  cout << "Double Talbe:" << endl;
  doubleTalbe.print();
    
  return 0;
}
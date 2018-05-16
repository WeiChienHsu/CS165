/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:   
                 1. Constructor: will then dynamically allocate memory for an int, 
                    using pInteger, and assign the parameter's value to that memory. 

                 2. Destructor: will deallocate that memory when the object is destroyed.
                 3. Copy Constructor: will correctly make a separate copy of the memory 
                    pInteger points to, and make pInteger in the new object point to it.
                 4. Operator Overloading: each of the two objects involved has its own 
                    separate copy of the memory that its own pInteger points to.  
                    The =operator should return a reference to the object pointed to by 
                    the this pointer. 
                 5. setMyInt & getMyInt : getting and setting the value of the int that pInteger points to.
*********************************************************************/
# include <iostream>
# include "MyInteger.hpp"


MyInteger::MyInteger(int num) {
  pInteger = new int;
  *pInteger = num;
}

MyInteger::MyInteger(const MyInteger &obj){
  pInteger = new int;
  *pInteger = *(obj.pInteger);
}

MyInteger::~MyInteger() {
  delete []pInteger;
  pInteger = nullptr;
}

MyInteger& MyInteger::operator=(const MyInteger &right) {
  delete[] pInteger;
  pInteger = new int;
  *pInteger = *(right.pInteger);
  return *this;
}


void MyInteger::setMyInt(int num) {
  *pInteger = num;
}

int MyInteger::getMyInt() const {
  return *pInteger;
}
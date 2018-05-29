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

/***********************************
** Constructor
** dynamically allocate memory for an int, 
** using pInteger, and assign the parameter's 
** value to that memory. 
************************************/

MyInteger::MyInteger(int num) {
  // Allocate a memory to a single integer
  pInteger = new int;
  // Assign a value into the memory that pointer pointed to
  // pInteger ---> [ num ]
  *pInteger = num;
}

/***********************************
** Copy Constructor
** correctly make a separate copy of the memory 
** pInteger points to, and make pInteger in the 
** new object point to it.
************************************/
MyInteger::MyInteger(const MyInteger &obj){
  // Allocate a memory to a single integer
  pInteger = new int;
  // Assign a value into the memory that pointer pointed to
  *pInteger = *(obj.pInteger);
}


/***********************************
** Destructor
** deallocate that memory when the 
** object is destroyed.
************************************/
MyInteger::~MyInteger() {
  delete pInteger;
  pInteger = NULL;
}


/***********************************
** Operator Overloading
** each of the two objects involved has its own 
** separate copy of the memory that its own pInteger points to.  
** The =operator should return a reference to the object 
** pointed to by the this pointer. 
************************************/

MyInteger& MyInteger::operator=(const MyInteger &right) {
  // Delete the memory stored the original pointer pointed to
  delete pInteger;

  pInteger = new int;
  // Assign the value of right pointer pointed to for pointer in current class
  *pInteger = *(right.pInteger);
  return *this;
}

/***********************************
** setMyInt
** setting the value of the int that 
** pInteger points to.
** Used pInteger pointing to the address of integer variable num
************************************/
void MyInteger::setMyInt(int num) {
  *pInteger = num;
}


/***********************************
** getMyInt
** getting of the value of the int that 
** pInteger points to. 
** Directly reutnn the dereference value of pointer
************************************/
int MyInteger::getMyInt() const {
  return *pInteger;
}
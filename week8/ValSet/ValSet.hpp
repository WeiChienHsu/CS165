/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/22/18
** Description:  Template class called ValSet, which represents a mathematical set of values

                 The ValSet will store the values in an array, 
                 which will need to grow if it gets full.

                 ValSet should have the following data members:
                    1.a pointer-to-T : points to a dynamically 
                      allocated array (of T) that holds the values that are part of the set.

                    2.an int that holds the current size of the array - 
                      it will need to be updated whenever the add() method creates a larger array

                    3.an int that holds the number of values that are currently part of the set - 
                      it will need to be updated in the add() and remove() methods
                 
                 The ValSet class should have the following methods:
                    1.a default constructor: initializes the pointer data member to point to an 
                      array of size 10, initializes the variable that stores the size of the array 
                      to 10, and initializes the variable that stores the number of values in the 
                      set to zero.

                    2. a copy constructor: initializes the pointer data member to point to an array 
                       of the same size as the one being copied, copies over the array values, and 
                       also copies the values for the size of the array and the number of values in 
                       the set.

                    3. an overloaded assignment operator: initializes the pointer data member to point 
                       to an array of the same size as the one being copied, copies over the array 
                       values, copies the values for the size of the array and the number of values 
                       in the set, and returns a reference to the object pointed to by the this pointer.

                    4. a destructor: deallocates the dynamically allocated array

                    5. size(): should return the number of values currently in the ValSet
                    6. isEmpty(): should return true if the ValSet contains no values, and return false otherwise
                    7. contains(): should take a parameter of type T and return true if that value 
                                   is in the ValSet, and return false otherwise.

                    8. add(): should take a parameter of type T and add that value to the ValSet 
                              (if that value is not already in the ValSet) - if the array is currently 
                              full and you need to add another value, then you must first increase the 
                              size of the array by allocating a new array that is twice as large, copying 
                              the contents of the old array into the new array, redirecting the data 
                              member pointer to the new array, and deallocating the old array 
                              (avoid memory leaks - order matters)

                    9. remove(): should take a parameter of type T and remove it from the ValSet 
                                 (if that value is in the ValSet) by shifting over all of the subsequent 
                                 elements of the array - it's okay if values that are no longer part of 
                                 the set are still in the array, so long as you do the right bookkeeping

                    10. getAsVector(): should return a vector (of type T) that contains all of the values 
                                       in the ValSet and only those values.  Order doesn't matter.

                    11. an overloaded + operator that returns a new ValSet that is the union of its two operands.
                        (contains all and only those values that were in either ValSet)
                    
                    12. an overloaded * operator that returns a new ValSet that is the intersection of its two operands 
                        (contains all and only those values that were in both ValSets)

                    13. an overloaded / operator that returns a new ValSet that is the symmetric difference of its two operands
                        (contains all and only those values that were in one ValSet or the other, but not both) 
*********************************************************************/
#include <iostream>
#include <memory>
#include <vector>

template <class T>
class ValSet {
  private:
    T *aptr;
    int curArraySize;
    int numberOfValue;
  public:
    ValSet(); // Default Constructor
    ValSet(const ValSet &); // Copy Constructor
    T &operator=(const ValSet &); // Overloaded Assignment Operator
    ~ValSet(); // Destructor
    int size();
    bool isEmpty();
    bool contains(T);
    void add(T);
    void remove(T);
    std::vector<T> getAsVector();
    
    ValSet<T> operator+(const ValSet &);
    ValSet<T> operator*(const ValSet &);
    // ValSet<T> operator/(const ValSet &); // 剩一題！

    void printSet() const; // Need to DELETE!!!!!!!
    int getArraySize() const; // Need to DELETE!!!!!!!
};

/**************************************
** Default constructor
** initializes the pointer data member to point to an 
** array of size 10, initializes the variable that stores 
** the size of the array to 10, and initializes the variable 
** that stores the number of values in the set to zero.
****************************************/
template <class T>
ValSet<T>::ValSet() {
  // pointer-to-T : points to a dynamically allocated 
  // array (of T) that holds the values that are part of the set.
  this->curArraySize = 10;
  this->numberOfValue = 0;
  this->aptr = new T[10];
}

/**************************************
** Copy constructor
** initializes the pointer data member to point to an array 
** of the same size as the one being copied, copies over 
** the array values, and also copies the values for the size 
** of the array and the number of values in the set.
****************************************/
template <class T>
ValSet<T>::ValSet(const ValSet &obj) {
  // copies the values for the size of the array 
  // and the number of values in the set
  this->curArraySize = obj.curArraySize;
  this->numberOfValue = obj.numberOfValue;
  // initializes the pointer data member to point to an array
  // of the same size as the one being copied
  this->aptr = new T[obj.curArraySize];
  // Copies over the array values
  for(int i = 0; i < obj.curArraySize; i++) {
    this->aptr[i] = obj.aptr[i];
  }
}

/**************************************
** Overloaded assignment operator
** initializes the pointer data member to point 
** to an array of the same size as the one being copied, copies over the array 
** values, copies the values for the size of the array and the number of values 
** in the set, and returns a reference to the object pointed to by the this pointer.
****************************************/
template <class T>
T& ValSet<T>::operator=(const ValSet<T> &right) {
  // Delete the memory stored the original array
  delete[] this->aptr;

  // initializes the pointer data member to point 
  // to an array of the same size as the one being copied
  // copies over the array values
  this->aptr = new T[right.curArraySize];
  for(int i = 0; i < right.curArraySize; i++) {
    this->aptr[i] = right.aptr[i];
  }
  // copies the values for the size of the array 
  // and the number of values in the set
  this->curArraySize = right.curArraySize;
  this->numberOfValue = right.numberOfValue;
  // returns a reference to the object pointed to by the this pointer
  return &this->aptr;
}

/**************************************
** Destructor
** deallocates the dynamically allocated array
****************************************/
template <class T>
ValSet<T>::~ValSet() {
  delete []this->aptr;
}

/**************************************
** size()
** return the number of values currently in the ValSet
****************************************/
template <class T>
int ValSet<T>::size() {
  return this->numberOfValue;
}

/**************************************
** isEmpty()
** return true if the ValSet contains no values, and return false otherwise
****************************************/
template <class T>
bool ValSet<T>::isEmpty() {
  return this->numberOfValue == 0;
}

/**************************************
** contains()
** take a parameter of type T and return true if that value 
** is in the ValSet, and return false otherwise.
****************************************/
template <class T>
bool ValSet<T>::contains(T p) {
  for(int i = 0; i < this->numberOfValue; i++) {
    if(this->aptr[i] == p) {
      return true;
    }
  }
  return false;
}

/**************************************
** add()
** take a parameter of type T and add that value to the ValSet 
** (if that value is not already in the ValSet) 
** 
** if the array is currently full and you need to add another value, 
** then you must first increase the size of the array by:
** 1. allocating a new array that is twice as large, 
** 2. copying the contents of the old array into the new array, 
** 3. redirecting the data member pointer to the new array
** 4. deallocating the old array (avoid memory leaks - order matters)
****************************************/
template <class T>
void ValSet<T>::add(T newValue) {
  // if that value is not already in the ValSet
  if(!this->contains(newValue)) {
    // if the array is not currently full : Add into the array
    if(this->numberOfValue < this->curArraySize) {
        this->aptr[this->numberOfValue] = newValue;
        numberOfValue++;
    } else {
      // if the array is currently full
      // allocating a new array that is twice as large 
      T *temp_aptr = new T[this->curArraySize * 2];

      // copying the contents of the old array into the new array
      for(int i = 0; i < this->curArraySize; i++) {
        temp_aptr[i] = this->aptr[i];
      }

      // deallocating the old array
      delete [] this->aptr;

      // redirecting the data member pointer to the new array
      this->aptr = temp_aptr;

      // Update the value of currentArraySize and numberOfValue
      // and assign the New Value into our re-sized array
      this->curArraySize *= 2;
      this->aptr[this->numberOfValue] = newValue;
      this->numberOfValue++;
    }
  }
}

/**************************************
** remove()
** take a parameter of type T and remove it from the ValSet 
** (if that value is in the ValSet)
** 
** by shifting over all of the subsequent 
** elements of the array - it's okay if values that are no longer part of 
** the set are still in the array, so long as you do the right bookkeeping
****************************************/
template <class T>
void ValSet<T>::remove(T removeValue) { 
  // If that value is int the ValSet
  if(this->contains(removeValue)) {
    // Find the removeValue Index
    int removeValueIndex;
    for(int i = 0; i < this->numberOfValue; i++) {
      if(this->aptr[i] == removeValue) {
        removeValueIndex = i;
        break;
      }
    }

    // Update the value of numOfValue
    this->numberOfValue--;

    // Remove the removeValue out of our original 
    // REASON why I would like to use a temp_ptr and create a new Array
    // is that since I count the size by directly reutrning numberOfValue
    // and in the add(), I used numberOfValue and curArraySize to judge if
    // we needed to re-size our array. When remove() was called several times
    // but the rest of removeValues are still stay in the array, we couldn't
    // know if we need to resize the array.

    // allocating a new array that is as the same large 
    T *temp_aptr = new T[this->curArraySize];

    // copying the contents of the old array into the new array without removeValue
    for(int i = 0; i < removeValueIndex; i++) {
      temp_aptr[i] = this->aptr[i];
    }
    // copying the rest after removeValue Index
    for(int i = removeValueIndex; i < this->numberOfValue; i++) {
      temp_aptr[i] = this->aptr[i+1];
    }

    // deallocating the old array
    delete [] this->aptr;

    // redirecting the data member pointer to the new array
    this->aptr = temp_aptr;

  }
}

/**************************************
** getAsVector()
** return a vector (of type T) that contains all of the values 
** in the ValSet and only those values.  Order doesn't matter.
****************************************/
template <class T>
std::vector<T> ValSet<T>::getAsVector() {
    std::vector<T> valVector;
    for(int i = 0; i < this->numberOfValue; i++) {
      valVector.at(i) = this->aptr[i];
    }

    return valVector;
}

/**************************************
** overloaded + operator
** returns a new ValSet that is the union of its two operands
** (contains all and only those values that were in either ValSet)
****************************************/
template <class T>
ValSet<T> ValSet<T>::operator+(const ValSet &right) {
  // Intialize temp array to hold the original array
  T *temp_aptr = new T[this->curArraySize];

  // Copy the values to the temp array
  for(int i = 0; i < this->numberOfValue; i++) {
    temp_aptr[i] = this->aptr[i];
  }

  // Allocate the old array and Reinitialize it
  // with a larger size (this->currentArraySize + right->currentArraySize)
  delete [] this->aptr;
  this->aptr = new T[this->numberOfValue + right.numberOfValue];

  // copying the contents of the old array 
  // and added array into the new array
  for(int i = 0; i < this->numberOfValue; i++) {
    this->aptr[i] = temp_aptr[i];
  }

  for(int i = this->numberOfValue; i < this->numberOfValue + right.numberOfValue; i++) {
    this->aptr[i] = right.aptr[i];
  }

  // Return a ValSet by Copy constructor 
  return ValSet(*this);
}


/**************************************
** overloaded * operator
** returns a new ValSet that is the intersection of its two operands 
** (contains all and only those values that were in both ValSets)
****************************************/
template <class T>
ValSet<T> ValSet<T>::operator*(const ValSet & right) {
  // Intialize temp array to hold the original array
  T *temp_aptr = new T[this->curArraySize];

  // Copy the values to the temp array
  for(int i = 0; i < this->numberOfValue; i++) {
    temp_aptr[i] = this->aptr[i];
  }

  // Allocate the old array and Reinitialize it with the same size
  delete [] this->aptr;
  this->aptr = new T[this->numberOfValue];

  // Intialize a counter
  int count = 0;

  // Search for the value that exists in both ValSets
  for(int i = 0; i < this->numberOfValue; i++) {
    for(int j = 0; j < right.numberOfValue; j++ ) {
      // If value exits in Both ValSets, Add it into current Array
      if(temp_aptr[i] == right.aptr[j]) {
        this->aptr[count] = right.aptr[j];
        count++;
      }
    }
  }

  // Return a ValSet by Copy constructor 
  return ValSet(*this);
}



/**************************************
** overloaded / operator
** returns a new ValSet that is the symmetric difference of its two operands
** (contains all and only those values that were in one ValSet or the other, 
** but not both)
****************************************/
// template <class T>
// ValSet<T> ValSet<T>::operator/(const ValSet &right) {

// }




template <class T>
void ValSet<T>::printSet() const {
  for(int i = 0; i < this->numberOfValue; i++) {
    std::cout << this->aptr[i] << std::endl;
  }
}

template <class T>
int ValSet<T>::getArraySize() const {
  return this->curArraySize;
}
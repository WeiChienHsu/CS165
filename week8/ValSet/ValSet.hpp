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


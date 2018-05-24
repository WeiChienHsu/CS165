# Exceptoins, Templates and the Standard Template Library(STL)

- throwing and catching exceptions as a way to gracefully handle error conditions
- function and class templates - the C++ way to create generic functions and classes
- the Standard Template Library (STL)


***

## Exception (Run time behavior)
- Try() and Catch()
- Simple Example: throw the error and skip the rest of try scope
```c++

int main() {
  try {
    throw 10;
    
    // Skip pass this
    std::cout << "I shouldn't see this" << std::endl;
  }
  catch(int e) {
    std::cout << "An exception occurred. Exception number: " << e << std::endl;
  }

  return 0;
}
```

#### Error: libc++abi.dylib: terminating with uncaught exception of type char const*
- C Style and C++ style String
```c++
throw "Opps, something bad happened!";
catch(std::string e) 
```

### Most Specific need to near the try method
Once one catch block was called, others will automatacilly be dismissed.

```c++
int main() {
  std::string s = "Opps, something bad happened!";

  try {
    throw s;
    throw 10;
    

    // Skip pass this
    std::cout << "I shouldn't see this" << std::endl;
  }
  catch(int e) {
    std::cout << "An exception occurred. Exception number: " << e << std::endl;
  }

  catch(std::string e) {
    std::cout << e << std::endl;
  }

  catch(...) {
    std::cout << "Something went wrong but we don't know why!" << std::cout;
  }

  return 0;
}
```
***

## Customized Exception

```c++
#include <iostream>
#include <string>
#include <stdexcept>

class math_error{};
class divide_by_zero : public math_error{};

double safe_divide(double a, double b) throw (divide_by_zero) {
    if(b == 0) {
      divide_by_zero d;
      throw d;
    }

    std::cout << "I shouldn't see this either." << std::endl;
    
    return a / b;
}

int main() {
  std::string s = "Opps, something bad happened!";

  try {
    safe_divide(4, 0);
    // Skip pass this
    std::cout << "I shouldn't see this" << std::endl;
  }

  catch(divide_by_zero) {
    std::cout << "Attempted to divided by ZERO" << std::endl;
    exit(-1);
  }

  // Parent Class won't be called if you put it away from try
  catch(math_error) {
    std::cout << "Attempted to event new MATH" << std::endl;
    exit(-1);
  }

  catch(...) {
    std::cout << "Something went wrong but we don't know why!" << std::endl;
  }


  return 0;
}
```


## Std Exception

```c++
int main() {
  std::vector<int> v;
  v.push_back(10);
  try {
    std::cout << v.at(15) << std::endl;  
  }
  catch(std::out_of_range e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
```
***

## Exception
Exceptions are used to signal errors or unexpected events that occur while a program is running.

One way handling complex error conditions is with exception. An exception is a value or an object that signals an error. When error occurs, an exception is said to be thrown vecause control will pass to a part of the program that catches and handles that type of error.

To handle an exception, a program must have a try/catch construct.

```c++
try {
  // code here calls functions or obejct member
  // functions that might throw an exception
}

catch(exception parameter) {
  // code here handles the exception
}
```

***

## Object Oriented Exception 
### Extracting Information from the Exception Class
- Inner Exception Class for "OutOfRange" with a public value constructoring by input value (Which could extract the information from user input)

```c++
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
```

- Define Inner Class in the cpp file
- Define the getInput method-> if value out of boundary: THROW the ERROR(IntRange::OutOfRange(input))
```c++
#include "IntRange.hpp"
#include <iostream>
using namespace std;

IntRange::IntRange(int low, int high) {
  this->lower = low;
  this->upper = high;
}

int IntRange::getInput() {
  cin >> this->input;
  if(this->input < this->lower || this->input > this->upper) {
    throw IntRange::OutOfRange(input);
  }
  return this->input;
}

IntRange::OutOfRange::OutOfRange(int input) {
    this->value = input;
}
```

- Main Function
```c++
int main() {
  IntRange range(5, 10);
  int userValue;

  cout << "Enter a value in the range 5 - 10: " << endl;
  
  try {
    userValue = range.getInput();
    cout << "You entered: " << userValue << endl;
  }

  catch(IntRange::OutOfRange e) {
    cout << "That value " << e.value << " is our of range. \n";
  }

  cout << "End of the program \n";
  return 0;
}

```

***
## Static Function

The this pointer cannot be used in a static member function since static member function are not called through any instance of their class. Moreover, a static member function cannot access an instance member of its class unless it specifies what instance the member belongs to.

For example, in the class:

```c++
class StatAccess {
  private:
    int x;
  public:
  static void output(StatAccess a) {
    cout << a.x;
  }
  StatAccess(int x) { this-> x = x}
}

***

# Function Template

A function template is a generic function that can work with different data types. The programmer writes the specificaions of the function but substitutes parameters for data types. When the compiler encounters a call to the function, it denerates code to handle the specific data type used in the call.

A function templates is not an actual function, but a "mold" the compiler uses to generate one or more functions. When writing a function template, you do not have to specify actuall types for the parameters, return value, or local variables. Instead, you use a type parameter to specify a generic data type. 

- T is the type parameter, or generic data type. The header defines square as a function that returns a value of type T and uses a parameter, number, which is also type T.

```c++
// Template definition for square function
template <class T>
T square(T number) {
  return number * number;
}
```

```c++
int main() {

  cout << "Enter an INTEGER\n";
  int iValue;
  cin >> iValue;


  cout << "The square is: " << square(iValue) << endl;

  cout << "Enter a Double\n";
  double dValue;
  cin >> dValue;

  cout << "The square is: " << square(dValue) << endl;

  return 0;
}
```
***
## Swap Function Template
```c++
template<class T>
void swapAB(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
```
- Or use the library of algorithm - swap

```c++
#include <algorithm> // Needed for swap
swap(a, b);
```
***
## Operators in Function Template

```c++
// Template for minimum of an array
template <class T>
T minimun(T arr[], int size) {
  T smallest = arr[0];
  for(int i = 0; i < size; i++) {
    if(arr[i] < smallest) {
      smallest = arr[i];
    }
  }
  return smallest;
}
```

***
## Function Template with Multiple Types
- More than one generic type may be used in a function template.

```c++
template <class T1, class T2, class T3>
void echoAndReverse(T1 a1, T2 a2, T3 a3) {
  cout << a1 << " : " << a2 << " : " << a3 << endl;
  cout << a3 << " : " << a2 << " : " << a1 << endl; 
}
```

***
## Overriding Template

```c++
template <class T>
T sum(T a1, T a2) {
  return a1 + a2;
}

template <class T>
T sum(T a1, T a2, T a3) {
  return a1 + a2 + a3;
}

```

***
## Class Template
Template might also be used to create generic classes and abstract data types.

Function templates are used whenever we need several different functions that have the same problem-solving logic, but differ only in the types of the parameters they work with. 

### Example : SimpleVector
This class template will store elements of type T in a dynamically generated array. This explain why the pointer aptr, which will point to the base of this array, is declared to be of type T[]. We have used a unique_ptr for the type of aptr because a SimpleVector object will not share the dynamicaly allocated array with any other part of the program.

```
- SimpleVector<double>
- SimpleVector<char>
- SimpleVector<string>
```
#### SimpleVector.hpp
- Constructor
- Copy Constructor
- Destructor
- size method
- Override [] operator
- print method

```c++
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
```

#### SimpleVector.cpp

```c++
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
```

***
## Class Template and Inheritance
- Inheritance can be applied to class templates.
- Add a SearchableVector inheried from SimpleVector.

```c++

```

***
## Array Dynamic Allocation
I am trying to get this function to create anew array to be 2x the size of the array argument, copy the contents into the new array, and for the second half of the array, create new values by doing 2*the values in the first half of the array, then delete the original array. Repeat this process for the specified number of times, then return the new array. 

```c++
int *ArrayDynamicAllocation(int array[], int size, int number)
{
   int *new_array = NULL;
   int *tmp_array = new int[array.length()];
   for(int k=0; k<array.length(); k++)//Initial array copying.
       tmp_array[k] = array[k];

   for(int i=0; i<number; i++)//Array range 0 to n-1
   {
      new_array = new int[size*2];
      for(int j=0; j<size; j++)//Array range 0 to n-1
      {
         new_array[j]=tmp_array[j];
         new_array[j+size]=2*tmp_array[j];
      }
      delete[] tmp_array //Deleting old array
      size=size*2; 
      tmp_array = new int[size] //Allocating memory for next iteration
      for(int k=0; k<size; k++)
        tmp_array[k] = new_array[k];//Copying array for next iteration
  }
  delete[] tmp_array;// To free memory
  return new_array;
};
```
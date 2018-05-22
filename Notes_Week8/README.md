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
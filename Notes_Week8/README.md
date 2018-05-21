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

# Exceptoins, Templates and the Standard Template Library(STL)

- throwing and catching exceptions as a way to gracefully handle error conditions
- function and class templates - the C++ way to create generic functions and classes
- the Standard Template Library (STL)


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

***
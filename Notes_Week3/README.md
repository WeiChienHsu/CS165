# Introduction to Class and Objects

- Classes provide a higher level of abstraction.

- They allow us to bundle together data that define the state of an object together with the functions that act on that data to form a self-contained unit.  

- Encapsulation: Making units (whether functions or classes) as self-contained as possible.  

- Abstraction and Encapsulation are closely related concepts and are recurring themes in the field of computer science.

Once you've finished defining a class, a programmer should be able to use it as a "black box", where all they need to know about is the publicly accessible member functions that make up the interface of the class.  They should not need to know anything about the private members of the class in order to use it.  

If you later decided to change the internal data or algorithms of the class (without changing the interface), that shouldn't cause any problems for any code that uses that class.


If a file needs to use a class that is defined in another file, then it needs to #include the header (.hpp) file for that class.  In the example below, both Movie.cpp and the file that contains the main function need to know about the interface for the Movie class, so both of those files need to #include "Movie.hpp".  You should never #include any .cpp files - only header files.

#### Movie.hpp
```c
#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

// Defines the interface of the Movie class
class Movie
{
private:
    std::string title;
    std::string director;
    int yearReleased;
    int lengthInMinutes;
public:
    Movie();
    Movie(std::string, std::string, int, int);
    void setTitle(std::string);
    std::string getTitle();
    void setDirector(std::string);
    std::string getDirector();
    void setYearReleased(int);
    int getYearReleased();
    void setLengthInMinutes(int);
    int getLengthInMinutes();
    void printInfo();
};
#endif
```
#### Movie.cpp
```c
#include <iostream>
#include <string>
#include "Movie.hpp"

Movie::Movie()
{
    setTitle("");
    setDirector("");
    setYearReleased(0);
    setLengthInMinutes(0);
}

Movie::Movie(std::string titleIn, std::string directorIn, int yearIn, int lengthIn)
{
    setTitle(titleIn);
    setDirector(directorIn);
    setYearReleased(yearIn);
    setLengthInMinutes(lengthIn);
}

void Movie::setTitle(std::string titleIn)
{
    title = titleIn;
}

std::string Movie::getTitle()
{
    return title;
}

void Movie::setDirector(std::string directorIn)
{
    director = directorIn;
}

std::string Movie::getDirector()
{
    return director;
}

void Movie::setYearReleased(int yearIn)
{
    yearReleased = yearIn;
}

int Movie::getYearReleased()
{
    return yearReleased;
}

void Movie::setLengthInMinutes(int lengthIn)
{
    lengthInMinutes = lengthIn;
}

int Movie::getLengthInMinutes()
{
    return lengthInMinutes;
}

void Movie::printInfo()
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Year released: " << yearReleased << std::endl;
    std::cout << "Length in minutes: " << lengthInMinutes << std::endl;
    std::cout << std::endl;  // just to get a blank line
}
```

#### main method
```c
#include <iostream>
#include "Movie.hpp"

int main()
{
    Movie mov1("Sharktopus", "Charlie Chaplin", 1000, 503);
    mov1.printInfo();
    
    mov1.setDirector("Winston Churchill");
    mov1.printInfo();
    
    Movie mov2;
    mov2.printInfo();
    
    return 0;
}
```
- 如果要直接new出一個新的mov2(使用 default constructor)
- 不需要後面的括號
```
movieList.cpp:9:15: warning: empty parentheses interpreted as a function declaration [-Wvexing-parse]
    Movie mov2();
              ^~
movieList.cpp:9:15: note: remove parentheses to declare a variable
    Movie mov2();
```

#### default constructor - Movie()
This default constructor sets the data members to values that won't cause printInfo to crash, but probably shouldn't be used anyway until the set methods are used to give data members reasonable values.

The values of the data members could be set directly within the constructor, but if we keep the "setting" code localized in one place, that means any changes to that code only have to happen in one place.

Please keep straight the difference between the parameters of a constructor and the data members of an object. 

The parameters of the constructor only exist for the duration of the function call.  The data members of an object persist for the lifetime of that object. 


***
# Into to Class and Object 
Objects are instances of a class. 
Class is a blueprint to build up an Object.
They are created with a definition statement after the class has been declared.

## Abstract Data Types
Abstraction is a general model of something. Definition that includes only the gengeral caharacteristics of an object without the details that characterize specific instances of the object.

Details of the internal components, organiztion and operations of an object are kept separate from the description of what it can do and how to operate it.

In Programming, inorder to focus on the bigger picture of creating a working applicaion,programmers need to be able to use certain objects and routines without having to be concerned with the details of their implementaions.

### Object-Oriented programming
Centered around objects that encapsulate both data and the function that operate on them.

### Class and Access Specifiers
Designate who can access various members of the class.
```c++
class Circle {
  piblic:
    void setRadius(double r) {
      radius = r;
    }
  private:
    double raduis;
}
```
```c++
Circle circle1;
circle.setRaduis(1);
```

## Defining Member function
"::" the scope resolution operator. It's needed to indicate that these are class member functions and to tell the compiler which class they belong to.
```c++
#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:
    double radius;
  public:
    void setRadius(double r); // These are prototypes or the member function
    double calcArea();
};

// The member function implemenation secion follows. It contains the 
// acutal function definitions for the Circle class member functions.

/*********************************************************************
**  Circle :: setRadius
**  This function copies the argument passed into the parameter to
**  the private member variable radius.
*********************************************************************/
void Circle::setRadius(double r) {
  radius = r;
}

/*********************************************************************
**  Circle :: calcArea
**  Calculate the Circle object's area
*********************************************************************/
double Circle::calcArea() {
  return 3.14 * pow(radius, 2);
}
/*********************************************************************
**  Main function
*********************************************************************/
int main() {
  Circle circle1, circle2;
  circle1.setRadius(5);
  circle2.setRadius(10);

  cout << "Circle1 area: " << circle1.calcArea() << endl;
  cout << "Circle2 area: " << circle2.calcArea() << endl;
}
```

## More on Inline function
When design a class, we need to decide which member functinos to write as inline functions within the class declaration and which ones to define outside the class.

Inline functions are handled completely differently by the compiler than regular functions.

#### Regular function:
Each time when a regular function is called, a number of special items(address to return, the value of the function argument) must be stored in a section of memory called the "stack".

In addition, local variables are created and a location is reserved to hold the function's return value. All this overhead, which sets the stage for a function call takes CPU time.

#### Inline function:
Inline expression, the compiler repaces every call to the function with the actual code of the function itself.

If the function is multiple times, increasing the size of the program.


## Constructiors
A member function that is automatically called when a class object is created.(Not allow to have return type)

#### Default Constructos (Without argument)
- Could only have one default constructor
```c++
class Sale {
  privare:
    double taxRat;
  public:
    Sale();
    Sale(double rate);
};

Sale::Sale() {
  raxRat = 0.0;
}

Sale::Sale(double rate) {
  raxRat = rate;
}

int main() {
  Sale sale1(1.5);
  Sale sale2;
}
```

### Priavte Member Function
Function for internal processing that should not be called by code outside the class.
(ex. isNewLargest())

## Passing Objects to Functions
Class objects may be passed as argument to function by both value or reference.


### Constant Reference Parameters (Constant function)
- Passing an object by value requires making a copy of all of the object's members. If it has many members, it will slow down the program execution.
- Passing an object by reference is faster because no copy has to be made since the function has access to the original object.
- Passing an object by reference is preferable
- But!! it can call its setter funtion and alter its member data.
- To protect an object when it is passe as an argument, without making a copy, it can be passed as a "constant reference".
- It can only call accessor function.
```c++
void showValue(cont InventoryItem& ) // Function prototype
void showValue(cont InventoryItem& item) // Function header
```
### Example



***


## Returning an Object from a Function



## Object Composition 
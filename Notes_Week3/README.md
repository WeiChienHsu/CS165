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
```c++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryItem {
  private:
    int partNum;
    string description;
    int onHand;
    double price;
  public:
    void storeInfo(int p,string d, int oH, double cost);

    int getPartNum() const {
      return partNum;
    }

    string getDescription() const {
      return description;
    }

    int getOnHand() const {
      return onHand;
    }

    double getPrice() const {
      return price;
    }
};

void InventoryItem::storeInfo(int p,string d, int oH, double cost){
  partNum = p;
  description = d;
  onHand = oH;
  price = cost;
}

// Function prototypes for client program
InventoryItem creatItem();
void showValues(const InventoryItem&);

int main() {
  InventoryItem part = creatItem();
  showValues(part);
  return 0;
}

InventoryItem creatItem() {
  InventoryItem tempItem;
  int partNum;
  string description;
  int qty;
  double price;

  cout << "Enter data for the new part number \n";
  cout << "Part number: \n";
  cin >> partNum;

  cout << "Description: ";
  cin.get();

  getline(cin, description);

  cout << "Quantity on hand: ";
  cin >> qty;
  cout << "Unit price: ";
  cin >> price;

  tempItem.storeInfo(partNum, description, qty, price);
  return tempItem;
}

void showValues(const InventoryItem& item) {
  cout << "##################" << endl;
  cout << "Part Number: " << item.getPartNum() << endl;
  cout << "Description: " << item.getDescription() << endl;
  cout << "Units On Hand: " << item.getOnHand() << endl;
  cout << "Price: " << item.getPrice() << endl;
}
```
### Object Composition 
It is possible for a class to have a member variable that is an instance of another class. 

***

# Software Engineering: 
## Separating Class Specification, Implemenation, and Client Code
Usually class declarations are stored in their own header files and member funtion definitions are stored in their own .cpp files.

- Class specification file: name of the class specification file is usually the same as the name of the class.
- Any program that uses the class should #include this header file.
- The class .cpp file should be compiled and linked with the application program that uses the class. Also known as "client program(with main function)". The process can be automated with a project or make utility. Integrated development environments such as Visual Studio also provide the means to create multi-file projects.

#### Contents of Rectangle.h
The #ifndef directive that appears called an include guard.

#### ifndef 
means: "if not defined"

#### define DEF_ARME 
speaks for itself: here the "empty macro" "DEF_ARME" is defined. We can see this construction very often in header files: your whole header file will be included in these:

#### ifndef HEADER_NAME
#### define HEADER_NAME
(here the code you want to include only once, as is general the case for headers)

#### endif
This way: the first time you include the header file, the macro "HEADER_NAME" isn't defined yet, so it will be defined and the header code will be included. If you include the same header later on, HEADER_NAME will be defined already, so the same code won't be included another time.

NOTE: The preprocessor directive



```c++
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        double length;
        double width;
    public:
        void setLength(double);
        void setWidth(double);
        double getLength();
        double getWidth();
        double calcArea();
}
#endif
```

### Performing Input/Output
We avoided doing any I/O inside the class. 
Unless the class is specifically designed to perform I/O, is is best to leave opeations such as user input and output to the person designing the applixation .

***

# Enumerated Data Types
Even though the enumerateors of an enumerated data type are stored in memory as integers, you cannot directly assign an integer value to an enum variable.

## using Strongly Typed enums in C++11
```c++
enum class Presidents { MIKINLEY, ROOSEVELT, TAFT};
enum class VicePresidens {ROOSEVELT, FAIRVVANK, SHERMAN};
```
```c++
#include <iostream>
using namespace std;

enum class Presidents {MIKINLEY, ROOSEVELT, TAFT};
enum class VicePresidents {ROOSEVLT, FARTPANLS, SEJADME};

int mian() {
  Presidents prez = Presidents::ROOSEVELT;
  VicePresidents vp1 = VicePresidents::ROOSEVLT;
  VicePresidents vp2 = VicePresidents::FARTPANLS;

  cout << static_cast<int>(prez) << " " << static_cast<int>(vp1) << " " << static_cast<int>(vp2) << endl;
  return 0;
}
```
***

## Implementaion of Account Project

- .h and .cpp Need to be a "FILE_NAME"
```c++
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Account.cpp"
```
- How to Read the user input, use the cin.get() and cin.ignore()
```c++
char readSelection(char MAX_SELECTION) {
  char selection = cin.get();
  cin.ignore();

  while(selection < '1' || selection > MAX_SELECTION) {
    cout << "Choice must between 1 and " << MAX_SELECTION << "Please Enter again: ";
    selection = cin.get();
    cin.ignore();
  }

  return selection;
}
```
- We could directly pass an Account Obejct into a function makeWithdrawl to deal with withdrawing.
- By account.getBalance(), account.withdraw() which will check if we have enough balance and make a withdrawal
```c
void makeWithdrawal(Account &account) {
  double dollor;
  cout << "Now you have : $" << account.getBalance() << endl;
  cout << "Please enter the amount you want to withdraw: " << endl;
  cin >> dollor;
  cin.ignore();
  if(account.withdraw(dollor)) {
    cout << "Wothdraw : $ " << dollor << endl;
    cout << "Now Your Balance is: $" << account.getBalance() << endl;
  } else {
    cout << "You don't have enough money in your bank!\n";
    cout << "Remind: $" << account.getBalance();
  }
}
```


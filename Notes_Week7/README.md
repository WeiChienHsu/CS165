# More about Classes and Object-Oriented Programming

- the this pointer and constant member functions
- static members
- friends of classes
- memberwise assignment
- copy constructors
- operator overloading
- type conversion constructors
- convert constructors
- calling base class constructors
- inheritance
- overriding base class functions
- type compatibility in inheritance hierarchies
- polymorphism and virtual member functions
- abstract base classes and pure virtual functions


***

## Class

[技術筆記 C++](http://twmht.github.io/blog/posts/cc/class.html)

- friend function: 簡單來說就是你在class裡面定義了一個friend function，這個function是在class的外面，同時這個function可以修改private data。

- const function: 在function後面如果加了const的話，就表示它不會修改任何的menber data，所以，const object不能夠呼叫non const function。

以下講權限範圍，如果沒有定義的話，則預設表示private。其實跟java很類似，差別在於java沒有friend class，而且java的預設權限是package scope。

- private: 只有自己或者是friend class看得到(其實就是可不可以直接存取的意思啦)。
- protected: 只有自己，friend class或者子類別才可以看得到。
- public: 任何可以看到這個class的地方都可以使用。



## Operator overloading
- Friend Function: can access variable directly (Even the private variable)
- Undirectly Function: Must use accrssors(getValue() in the class)
- Overloading as member function: Actually calling on class
```c++
#include <iostream>
using namespace std;

class integer {
  public:
    integer() {
      this -> val = 0;
    }

    integer(int value) {
      this -> val = value;
    }

    int value() {
      return val;
    }

    int value() const{
      return val;
    }

    void set_value(int value) {
      this -> val = value;
    }
    // Friend function
    friend const integer operator-(const integer&, const integer&);

    // Member Function
    const integer operator*(const integer &RHS) {
      return (this-> val * RHS.val);
    }

  private:
    int val;
};

// Undirectly Function
const integer operator+(const integer &LHS, const integer &RHS) {
  return integer(LHS.value() + RHS.value());
}

// Used Frinend Type of method to give the access for private value
const integer operator-(const integer &LHS, const integer &RHS) {
  return integer(LHS.val - RHS.val);
}

int main() {
  integer a(2);
  integer b(5);
  integer c = a + b;
  
  cout << a.value() << " + " << b.value() << " = " << c.value() << endl;
  cout << a.value() << " - " << b.value() << " = " << (a-b).value() << endl;
  cout << a.value() << " * " << b.value() << " = " << a.operator*(b).value() << endl;
  return 0;
}
```

### Member Function
- The best way to overload operator function
```c++
  const integer operator*(const integer &RHS) {
      return (this-> val * RHS.val);
    }
```

## I/O operator

```c++

    // Friend functions to I/O inside the class
    friend std::ostream& operator<<(std::ostream &outs, const integer& foo);
    friend std::istream& operator>>(std::istream &in, const integer& foo);   


std::ostream& operator<<(std::ostream &outs, const integer& foo){
    outs << foo.val;
    return outs;
}

std::istream& operator>>(std::istream &in, const integer& foo){
  in >> foo.val;
  return in;
}
```

## Assignment operator
#### Default Constructor
#### Assignment Operator
#### Copy Constructor
#### Destructor

```c++
    // Default Constructor
    integer() {
      this -> val = 0;
    }

    // Assignment Operator
    integer& operator=(const integer &RHS){
      this->val = RHS.val;
      return *this;
    }

    // Copy Constructor
    integer(integer &value) {
      this->val = value.val;
    }

    // Destructor
    ~integer() {
      // intentionaly left empty (to delete pointer in stack)
    }
```

***

# Inheritance

### Emample of Inheritance

```c++
#include <iostream>
#include <cmath>

enum { NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK};

class shape{
  public:
    shape() {
      this->side_count = -1;
      this->color = NOCOLOR;
    }

    shape(int sides) {
      this->side_count = sides;
    }

    double area() {
      if(side_count == -1) {
        return -17;
      } else {
        return 14;
      }
    }

    double perimeter() {
      return 0;
    }

  protected:
    int side_count;
    int color;

};

// Triangle inheritaed shape
class triangle : public shape{
  public:
  // Default Constructor
    triangle() : shape(3) {
      this->side1 = 0;
      this->side2 = 0;
      this->side3 = 0;
    }

    triangle(double side1, double side2, double side3) : shape(3) {
      this->side1 = side1;
      this->side2 = side2;
      this->side3 = side3;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {

      // this->perimeter()
      // Since the this is a pointer to the Instance of Object in this class
      double s = (*this).perimeter() /  2;
      return std::sqrt( s * (s - this->side1) *
                            (s - this->side2) *
                            (s - this->side3)
                      );
    }

    double perimeter() {
      return this->side1 + this->side2 + this->side3;
    }

  protected:
    double side1;
    double side2;
    double side3;

};

// Rectangle
class rectangle : public shape{
  public:
  // Default Constructor
    rectangle() : shape(4) {
      this->side1 = 0;
      this->side2 = 0;
    }

    rectangle(double side1, double side2) : shape(4) {
      this->side1 = side1;
      this->side2 = side2;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {
      return  this->side1 * this->side2;
    }

    double perimeter() {
      return this->side1 * 2 + this->side2 * 2;
    }

  protected:
    double side1;
    double side2;
};

// Square inherited from rectangle

class square : public rectangle{
  // Don't inherit Constructor and Destructor(Which was automacatially be called by compiler when this class ends)
  // Don't inherit private function (Used protected to access private-like function which only for child)

  public:
    square() : rectangle() {
      this->side1 = 0;
      this->side2 = 0;
    }

    square(double side) : rectangle(side, side) {
      this->side1 = side;
      this->side2 = side;
    }

    // Directly call the parent function of area in rectangle

    double area() {
      return rectangle::area();
    }

    double perimeter() {
      return rectangle::perimeter();
    }

  protected:
    
};



int main() {
  shape s;
  triangle t(3,4,5);
  rectangle r(4,5.5);
  square q(10);
  
  std::cout << "Area of shape s: " << s.area() << std::endl;
  std::cout << "Perimeter of shape s: " << s.perimeter() << std::endl;
  
  std::cout << "Area of triangle t: " << t.area() << std::endl;
  std::cout << "Perimeter of triangle t: " << t.perimeter() << std::endl;

    
  std::cout << "Area of rectangle r: " << r.area() << std::endl;
  std::cout << "Perimeter of rectangle r: " << r.perimeter() << std::endl;


  std::cout << "Area of Square q: " << q.area() << std::endl;
  std::cout << "Perimeter of Square q: " << q.perimeter() << std::endl;

  return 0;
}
```

## 


***

# Polymorphism

- Need to use s->area() to call the function in child class
```
member reference type 'shape *' is a pointer;
```

- Pass by reference and use a pointer in the print function


```c++
void print_area(shape *s, std::string name) {
    std::cout << "Area of " << s->name() << " s (should be " 
              << name << ") : " << s->area() << std::endl;
    std::cout << "Perimeter of " << s->name() <<  " s (should be " 
              << name << ") : " << s->perimeter() << std::endl;
}


print_area(&s, "shape");
```

- Change the parent function into virtual methods
- Vertual this allows us to write code in a way that when other come along and extend our classes so inherit from our base classes, other can pass in their child class in the place of our base class and through the magic of polymorphism other's versions of the functions will be called.
- In the child class, we need to overwrite the virtual method we might use in the future, or we won't make 

```c++
    virtual double area() {
      if(side_count == -1) {
        return -17;
      } else {
        return 14;
      }
    }

    virtual double perimeter() {
      return 0;
    }

    virtual std::string name() {
      return std::string("SHAPE");
    }
```

## Example

```c++
#include <iostream>
#include <cmath>
#include <string>

enum { NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK};

class shape{
  public:
    shape() {
      this->side_count = -1;
      this->color = NOCOLOR;
    }

    shape(int sides) {
      this->side_count = sides;
    }

    virtual double area() {
      if(side_count == -1) {
        return -17;
      } else {
        return 14;
      }
    }

    virtual double perimeter() {
      return 0;
    }

    virtual std::string name() {
      return std::string("SHAPE");
    }

  protected:
    int side_count;
    int color;

};

// Triangle inheritaed shape
class triangle : public shape{
  public:
  // Default Constructor
    triangle() : shape(3) {
      this->side1 = 0;
      this->side2 = 0;
      this->side3 = 0;
    }

    triangle(double side1, double side2, double side3) : shape(3) {
      this->side1 = side1;
      this->side2 = side2;
      this->side3 = side3;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {

      // this->perimeter()
      // Since the this is a pointer to the Instance of Object in this class
      double s = (*this).perimeter() /  2;
      return std::sqrt( s * (s - this->side1) *
                            (s - this->side2) *
                            (s - this->side3)
                      );
    }

    double perimeter() {
      return this->side1 + this->side2 + this->side3;
    }
    
    std::string name() {
      return std::string("TRIANGLE");
    }

  protected:
    double side1;
    double side2;
    double side3;

};

// Rectangle
class rectangle : public shape{
  public:
  // Default Constructor
    rectangle() : shape(4) {
      this->side1 = 0;
      this->side2 = 0;
    }

    rectangle(double side1, double side2) : shape(4) {
      this->side1 = side1;
      this->side2 = side2;
    }

    // Redefined our parent's method (Not same as the Overloading -> give a different signature)
    double area() {
      return  this->side1 * this->side2;
    }

    double perimeter() {
      return this->side1 * 2 + this->side2 * 2;
    }

    std::string name() {
      return std::string("RECTANGLE");
    }

  protected:
    double side1;
    double side2;
};

// Square inherited from rectangle

class square : public rectangle{
  // Don't inherit Constructor and Destructor(Which was automacatially be called by compiler when this class ends)
  // Don't inherit private function (Used protected to access private-like function which only for child)

  public:
    square() : rectangle() {
      this->side1 = 0;
      this->side2 = 0;
    }

    square(double side) : rectangle(side, side) {
      this->side1 = side;
      this->side2 = side;
    }

    // Directly call the parent function of area in rectangle

    double area() {
      return rectangle::area();
    }

    double perimeter() {
      return rectangle::perimeter();
    }

    std::string name() {
      return std::string("SQUARE");
    }

  protected:
    
};

void print_area(shape *s, std::string name) {
    std::cout << "Area of " << s->name() << " s (should be " 
              << name << ") : " << s->area() << std::endl;
    std::cout << "Perimeter of " << s->name() <<  " s (should be " 
              << name << ") : " << s->perimeter() << std::endl;
}


int main() {
  shape s;
  triangle t(3,4,5);
  rectangle r(4,5.5);
  square q(10);
  
  print_area(&s, "shape");
  print_area(&t, "triangle");
  print_area(&r, "rectangle");
  print_area(&q, "square");
  return 0;
}

```



***

## Redefined Function
A redefined function is a method in a descendant class that has a different definition than a non-virtual function in an ancestor class. Don't do this. Since the method is not virtual, the compiler chooses which function to call based upon the static type of the object reference rather than the actual type of the object.

## Override Function - Runtime

Child Class中相同的function name，去定義parent class中的virtual function，給予不同的implementation

- Polymorphic where we provide a different implementation of a virtual function

Polymorphism achieved during run-time is called ‘overriding.’  It is accomplished by using ‘inheritance’ and ‘virtual functions’. Function to be overridden is preceded by the keyword ‘virtual’ in a base class and redefined in a derived class without any keyword.

One of the most important thing to remember in case of overriding is that the prototype of the overridden function must not change while derived class redefines it. When overridden function is given a call, C++ determines which version of the function is called based on the ‘type of the object pointed by a pointer’ by which the function calling is done.

```c++
class base{
  public:
    virtual void funct(){  //virtual function of base class
      cout<<"This is a base class's funct()";
    }
};

class derived1 : public base{
  public:
    void funct(){  //virtual function of base class redefined in derived1 class
      cout<<"This is a derived1 class's funct()";
    }
};

class derived2 : public base{
  public:
    void funct(){  //virtual function of base class  redefined in derived2 class
      cout<<"This is a derived2 class's funct()";
    }
};

int main()
{
  base *p, b;
  derived1 d1;
  derived2 d2;

  *p=&b;
  p->funct(); //call to base class funct().

  *p=&d1;
  p->funct();  //call to derived1 class funct().

  *p=&d2;
  p->funct();  //call to derived2 class funct().
  
  return 0;
}

```


## Overload Function - Compile Time
相同的function name，給予不同的arguments(parameter list)

- Providing different function signature that does something different than the previous function.

Compile-time polymorphism is called ‘overloading.’ As overloading is generated from a concept of polymorphism, it provides “a common interface for multiple methods”. That means, if a function is overloaded, it contain same function name while it is redefined.

```c++
class overload{
  int a, b;
  public:
    int load(int x){    // first load() function
     a=x;
      return a;
    }

    int load(int x, int y){   //second load() function
     a=x;
      b=y;
      return a*b;
    }
};

int main(){
  overload O1;
  O1.load(20);  //first load() function call
  O1.load(20,40);  // second load() function call
}
``` 




## Key Differences Between Overloading and Overriding

1. The prototype of a function which is being overloaded differs because of the type and number of parameter that are passed to the overloaded function. On the other hand, the prototype of the overridden function does not change because an overridden function perform different action for different class it belongs to but with the same type and number of parameter.

2. The overloaded function name does not precede with any keyword whereas, the name of an overridden function precede with the keyord “Virtual” in base class only.

3. Which overloaded function is invoked depends on the type or number of parameter that is passed to the function. The overridden function of which class is invoked depends on, which class’s object address is assigned to the pointer, which invoked the function.

4. Which overloaded function is to be invoked is resolved during compile time. Which overridden function to be invoked is resolved during runtime.

5. Constructors can be overloaded but can not be overridden.

6. Destructors can not be overloaded, but they can be overridden.

7. Overloading achieves early binding as which overloaded function will be invoked is resolved during compile time. Overriding achieves late binding as the which overridden function will be invoke is resolved during runtime.

## Conclustion

Overloading and overriding appears similar, but this is not the case. Functions can be overloaded but, any class can not further redefine the overloaded function in future. A virtual function cannot be overloaded; they can only be overridden.

***

# Difference Between Inheritance and Polymorphism

[Difference Between Inheritance and Polymorphism](https://techdifferences.com/difference-between-inheritance-and-polymorphism.html)

Inheritance allows, code reusability and the polymorphism is, the occurrence of one function with different form. The basic difference between inheritance and polymorphism is that inheritance allows the already existing code to be reused again in a program, and polymorphism provides a mechanism to dynamically decide what form of a function to be invoked.

## Key Differences Between Inheritance and Polymorphism

1. Inheritance is creating a class that derives its feature from an already existing class. On the other hand, polymorphism is an interface that can be defined in multiple forms.

2. Inheritance is implemented on the classes whereas, the polymorphism is implemented on methods/functions.

3. As inheritance allows a derived class to use the elements and methods defined in the base class, the derived class does not need to define those elements or method it again so, we can say it increases code reusability and hence, reduces the length of the code. On the other hand, polymorphism makes it possible for an object to decide what form of the method it wants to invoke at both compile time and run time.

4. The inheritance can be classified as single inheritance, multiple inheritance, multilevel inheritance, hierarchical inheritance and hybrid inheritance. On the other hand, polymorphism is classified as overloading and overriding.

*** 

# This Pointer and constant member function

By default the compiler provides each member function of a class with an implicit parameter that points to the object through which the member function is called.

```c++
class Example{
  int x;
  public:
    Example(int a) { x = a; }

    void setValue(int a) {
      x = a;
    }
    void getValueAndObjectAddress() {
      std::cout << "The object at address: " << this << std::endl;
      std::cout << "The value is: " << this->x << std::endl;
    }
};

int main() {
  Example e(5);
  e.getValueAndObjectAddress();
  e.setValue(6);
  e.getValueAndObjectAddress();  
  return 0;
}
```

## Static Member Variable
It's possible to create a member variable that is shared by all the objects the same class.

```c++
#include <iostream>

class StatDemo {
  private:
    static int x;
    int y;

  public:
    void setX(int a) {
      this->x = a;
    }

    void setY(int b) {
      this->y = b;
    }

    void print_XY() {
      std::cout<< "X: " << this->x << std::endl;
      std::cout<< "Y: " << this->y << std::endl;
    }

};

int StatDemo::x = 0;

int main() {
  StatDemo a;
  StatDemo b;

  a.setX(100);
  a.setY(5);
  b.setY(10);

  a.print_XY();
  b.print_XY();

  return 0;
}
```

***

## Friends of Class

A function that is not a member of a class but has access to the private members of the class.

```
friend <return type><function name>(<parameter type list>);
```

## Example

- Allow Aux Class to access the corpBudget private variable in otehr Class Budget

### aux.hpp
```c++
#ifndef AUX_HPP
#define AUX_HPP

class Aux {
  private:
    double auxBudget;
  public:
    Aux() { auxBudget = 0; }
    void addBudget(double);
    double getDivBudget() const { return auxBudget;}   
};


#endif

```


### budget.hpp
- friend void Aux::addBudget(double);
- Let addBudget in Aux class could access the private variable.

```c++
#ifndef BUDGET_HPP
#define BUDGET_HPP
#include "aux.hpp"

class Budget {
  private:
    static double corpBudget;
    double divBudget;
  public:
    Budget() { divBudget = 0;}
    void addBudget(double b) {
      this->divBudget += b;
      this->corpBudget += divBudget;
    }

    double getDivBudget() const {return this->divBudget;}
    static double getCorpBudget() {return corpBudget;} 
    friend void Aux::addBudget(double);
};

#endif
```

### aux.cpp
- addBudget used the private variable "corpBudget" in Budget class

```c++
#include "aux.hpp"
#include "budget.hpp"

// Define the friend function
void Aux::addBudget(double b) {
  auxBudget += b;
  Budget::corpBudget += auxBudget;
}
```

### budget.cpp
- Assign a value to the static member
```c++
#include "budget.hpp"

// Define for the static member
double Budget::corpBudget = 0;
```


### main method
- Output
```
10
110
```

```c++
#include <iostream>
#include "budget.hpp"

int main() {
  Budget a;
  a.addBudget(10);
  std::cout << a.getCorpBudget() << std::endl;

  Aux b;
  b.addBudget(100);
  
  std::cout << a.getCorpBudget() << std::endl;

  return 0;

}
```
***

## Copy Constructors
Special Constructor that is called whenever a new object is created and initialized with the data of another object of the same class.

The default copy constructor copied the data of the existing object ot the new object using memberwise assignment.


```c++
class NumberArray {
  private:
    double *aPtr;
    int arraySize;

  public:
    NumberArray(int size, double value) {
      this->arraySize = size;
      aPtr = new double[arraySize];
      setValue(value);
    }

    void print() {
      for(int i = 0; i < this->arraySize; i++) {
        std::cout << this->aPtr[i] << " ";
      }
      std::cout<< " " << std::endl;
    }

    void setValue(double value) {
      for(int i = 0; i < arraySize; i++) {
        this->aPtr[i] = value;
      }
    }
};

int main() {
  NumberArray first(3, 10.5);
  NumberArray second = first;

  std::cout << "Value stored in first Object is : " << std::endl;
  first.print();
  std::cout << "Value stored in second Object is" << std::endl;
  second.print();
  std::cout << "Only change the second value" << std::endl;

  second.setValue(20);

  std::cout << "Value stored in first Object is : " << std::endl;
  first.print();
  std::cout << "Value stored in second Object is" << std::endl;
  second.print();
  

  return 0;
}
```

The reason changing the data in one object changes the other objects is that the memberwise assignment performed by the default copy constructor copies the value of the pointer in the first object to the pointer in the second object. Leaving both pointers point to the sane data in memory. Thus when one of the objects changes its data through its pointer, it affects the other object as well.


## Programmer-Defined Copy Constructor

Must have a single parameter that is a reference to the same class.

```c++
NumberArray(const NumberArray &obj)
```

The copy constructor avoid the problem of the default copy consturctor by allocating separate memory for the pointer of the new object before doing the copy:

```c++
NumberArray(const Number &obj) {
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];
  for(int i = 0; i < arraySize; i++) {
    aPtr[i] = obj.aPtr[i];
  }
}

```
The copy constructor should not change the object being copied, so it declared its argument as const. 

```
Value stored in first Object is :
10.5 10.5 10.5
Value stored in second Object is
10.5 10.5 10.5
Only change the second value
Value stored in first Object is :
10.5 10.5 10.5
Value stored in second Object is
20 20 20
```
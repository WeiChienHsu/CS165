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

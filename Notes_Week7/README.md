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


## Const operator
- Friend Function: can access variable directly (Even the private variable)
- Undirectly Function: Must use accrssors(getValue() in the class)

```c++
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

  private:
    int val;
};

const integer operator+(const integer &LHS, const integer &RHS) {
  return integer(LHS.value() + RHS.value());
}
```
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
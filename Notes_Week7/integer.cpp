#include <iostream>

class integer {
  public:

    integer(int value) {
      this -> val = value;
    }

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

    // Friend functions to I/O
    friend std::ostream& operator<<(std::ostream &outs, const integer& foo);
    friend std::istream& operator>>(std::istream &in, const integer& foo);   


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

std::ostream& operator<<(std::ostream &outs, const integer& foo){
    outs << foo.val;
    return outs;
}

std::istream& operator>>(std::istream &in, const integer& foo){
  in >> foo.val;
  return in;
}

int main() {
  integer a(2);
  integer b(5);
  integer c = a + b;
  
  std::cout << a << " + " << b.value() << " = " << c.value() << std::endl;
  std::cout << a.value() << " - " << b.value() << " = " << (a-b).value() << std::endl;
  std::cout << a.value() << " * " << b.value() << " = " << a.operator*(b).value() << std::endl;
  return 0;
}
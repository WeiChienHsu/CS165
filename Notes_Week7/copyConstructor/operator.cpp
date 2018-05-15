#include <iostream>

class Example {
  private:
    int n;
  public:
    Example(int num) {
      this->n = num;
    }

    int getValue() const {
      return this->n;
    }

    void operator=(const Example &right) {
      this->n = right.n;
      std::cout << "Assign the value of: " << right.n << " into LSH" << std::endl;
      std::cout << "Value of LSH now is: " << this->n << std::endl;
    }
};

int main() {
    Example LHS(10);
    Example RHS(100);

    std::cout << "LHS : " << LHS.getValue() << std::endl;
    LHS = RHS;
    return 0;

}
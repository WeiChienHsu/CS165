#include <iostream>
using namespace std;

class BaseDemo {
  public:
    BaseDemo() {
      cout << "Constructor in Base" << endl;
    }

    ~BaseDemo() {
      cout << "Destructor in Base" << endl;
    }
};

class ChildDemo : public BaseDemo {
  public:
    ChildDemo() {
    cout << "Constructor in Child" << endl;
    }

    ~ChildDemo() {
      cout << "Destructor in Child" << endl;
    }

};

int main() {
  ChildDemo a;
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Dog{
  public:
    int age;
    string name;
    void printName();
};

int main() {
  Dog herry, petter;
  herry.age = 10;
  herry.name = "Herry";
  herry.printName();
}

void Dog::printName() {
  cout << name << " is a Dog, age: " << age << endl;
}
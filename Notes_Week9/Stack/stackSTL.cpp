#include <iostream>
#include <vector>
#include <stack>

int main() {
  std::stack<double> dStack;

  for(double x = 2; x < 9; x++) {
    std::cout << "Pushing " << x << std::endl;
    dStack.push(x);
  }

  std::cout << "The size of the stack is: ";
  std::cout << dStack.size() << std::endl;

  while(!dStack.empty()) {
    std::cout << dStack.top() << std::endl;
    dStack.pop();
  }
  return 0;
}
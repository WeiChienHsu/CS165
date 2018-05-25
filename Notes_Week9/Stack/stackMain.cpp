#include "IntStack.hpp"
#include "DynIntStack.hpp"
#include <iostream>

int main() {
  // IntStack stack(4);
  // int values[] = {10, 20, 30, 40};

  // std::cout << "Pushing ... " << std::endl;
  // for(int i = 0; i < 4; i++) {
  //   stack.push(values[i]);
  //   std::cout << "Push: " << values[i] << std::endl;
  // }

  // std::cout << "Popign ... " << std::endl;
  // std::cout << "In the Stack it will like: " << std::endl;
  // for(int i = 0; i < 4 ; i++) {
  //   std::cout << stack.pop() << std::endl;
  //   std::cout << "---" << std::endl;
  // }

  DynIntStack dynStack;
  dynStack.push(10);
  std::cout << dynStack.pop() << std::endl;
  std::cout << dynStack.isEmpty() << std::endl;
  
  try {
    std::cout << dynStack.pop() << std::endl;
  } catch(DynIntStack::Underflow) {
     std::cout << "Stack is Empty!" << std::endl;
  }
  
  return 0;
}
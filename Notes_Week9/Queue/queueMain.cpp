#include "IntQueue.hpp"
#include "DynIntQueue.hpp"
#include <iostream>

int main() {
  DynIntQueue queue;
  for(int i = 0; i < 5; i++) {
    queue.enqueue(i*i);
  }
  
  for(int i = 0; i < 5; i++) {
    std::cout << queue.dequeue() << std::endl;
  }

  std::cout << "Is queue empty? " << queue.isEmpty() << std::endl;

  return 0;
}
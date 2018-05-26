#include "IntQueue.hpp"
#include <iostream>

int main() {
  IntQueue queue(5);
  for(int i = 0; i < 5; i++) {
    queue.enqueue(i*i);
  }

  std::cout << "Is queue full? " << queue.isFull() << std::endl;

  for(int i = 0; i < 5; i++) {
    std::cout << queue.dequeue() << std::endl;
  }

  std::cout << "Is queue empty? " << queue.isEmpty() << std::endl;

  return 0;
}
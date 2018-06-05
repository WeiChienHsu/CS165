#include <iostream>
#include "CFBoard.hpp"

int main() {
  CFBoard game1;
  std::cout << game1.makeMove(1, 'x') << std::endl;
  std::cout << game1.makeMove(1, 'x') << std::endl;
  std::cout << game1.makeMove(1, 'o') << std::endl;
  std::cout << game1.makeMove(1, 'o') << std::endl;
  std::cout << game1.makeMove(1, 'x') << std::endl;
  std::cout << game1.makeMove(1, 'x') << std::endl;
  std::cout << game1.makeMove(2, 'x') << std::endl;
  std::cout << game1.makeMove(2, 'x') << std::endl;
  std::cout << game1.makeMove(3, 'x') << std::endl;
  std::cout << game1.makeMove(3, 'x') << std::endl;
  std::cout << game1.makeMove(3, 'x') << std::endl;
  std::cout << game1.makeMove(4, 'o') << std::endl;
  std::cout << game1.makeMove(4, 'o') << std::endl;
  std::cout << game1.makeMove(4, 'o') << std::endl;
  std::cout << game1.makeMove(4, 'o') << std::endl;  
  game1.printGameState();

  // std::cout << game1.getGameState() << std::endl;
  // game1.printGameState();
  game1.print();

  return 0;
}
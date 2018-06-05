#include <iostream>
#include "CFBoard.hpp"

int main() {
  char mockBoard[6][7] = { 'x', 'e', 'x', 'o', 'o', 'o', 'x',
                           'o', 'x', 'o', 'o', 'o', 'x', 'o',
                           'x', 'x', 'o', 'x', 'o', 'x', 'x',
                           'x', 'o', 'x', 'o', 'x', 'o', 'x',
                           'o', 'x', 'x', 'o', 'x', 'o', 'o',
                           'o', 'x', 'x', 'x', 'o', 'o', 'x' 
  };

  CFBoard game(mockBoard);
  game.print();
  game.printGameState();
  game.makeMove(2,'o');
  game.printGameState();
  game.print();
  std::cout << game.makeMove(2,'o') << std::endl;
  return 0;
}
#include <iostream>
#include "CFBoard.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class Player {
  public:
    char name;
    int number;
    Player(char name) {
      this->name = name;
    }
    int randomNumber() {
      this->number = (rand() % 7) + 1;
      std::cout << "Player " << this->name << " chose " << this->number << std::endl; 
      return number;
    }
};

int main() {
  CFBoard game;
  Player O = Player('o');
  Player X = Player('x');
  srand(time(NULL));

  while(game.getGameState() == UNFINISHED) {
    while(!game.makeMove(O.randomNumber(),'o')) {
      if(game.getGameState() == O_WON ||
      game.getGameState() == X_WON ||
      game.getGameState() == DRAW) {
        break;
      }
    }

    if(game.getGameState() != UNFINISHED) break;

    while(!game.makeMove(X.randomNumber(),'x')) {
      if(game.getGameState() == O_WON ||
      game.getGameState() == X_WON ||
      game.getGameState() == DRAW) {
        break;
      }
    }
  }

  game.printGameState();
  game.print();

  return 0;
}
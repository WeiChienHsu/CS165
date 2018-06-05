#include "BBoard.hpp"
#include <iostream>
#include "Ship.hpp"
using namespace std;

int main() {
  Ship ship1("Kevin", 4);
  Ship ship2("Nick", 3);
  BBoard game;

  game.placeShip(&ship1, 3, 2, 'R');
  game.placeShip(&ship2, 4, 6, 'C');
  cout << game.getNumShipsRemaining() << endl;
  game.printBoard();
  cout << game.attack(2,3) << endl;
  cout << game.attack(3,3) << endl;
  cout << game.attack(3,2) << endl;
  cout << game.attack(3,4) << endl;
  cout << game.attack(3,5) << endl;
  cout << game.attack(3,6) << endl;
  game.printBoard();
  cout << game.getNumShipsRemaining() << endl;
  cout << game.attack(4,6) << endl;
  cout << game.attack(5,6) << endl;
  cout << game.attack(6,6) << endl;

  game.printBoard();
  cout << game.allShipsSunk() << endl;
  return 0;
}
#include "BBoard.hpp"
#include "Ship.hpp"
#include <iostream>

int main() {
  BBoard board;
  Ship ship1("Boaty McBoatface", 2);
  board.placeShip(&ship1, 2, 2, 'R');
  board.printBoard();
  std::cout << board.getNumShipsRemaining() << std::endl;
  board.attack(2, 3);
  board.attack(2, 2);
  board.attack(2, 3);
  std::cout << board.getNumShipsRemaining() << std::endl;
  std::cout << board.allShipsSunk() << std::endl;
  board.printBoard();
  return 0;
}
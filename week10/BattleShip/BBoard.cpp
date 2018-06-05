/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         06/01/18
** Description:  a class called CFBoard that represents a game board for 
                 playing Connect Four.

The BBoard class represents a 10x10 grid that holds some number of Ships.  It should have:

1. a 10x10 array of bools (for keeping track of what squares have been attacked)

2. a 10x10 array of Ship-pointers (for keeping track of which Ships occupy which squares)

3. a variable that keeps track of the number of ships that remain un-sunk

4. a constructor that initializes each element of the boolArray to false and each element 
of the Ship-pointer array to NULL 

5. a method called getAttacksArrayElement that takes a row and column (in that order) and 
returns the element at that position of the bool array.

6. a method called getShipsArrayElement that takes a row and column (in that order) and 
returns the element at that position of the ships array.

7. a method called getNumShipsRemaining that returns how many ships remain un-sunk

8. a method called placeShip that takes as parameters (in this order): a Ship object, 
the row and column of the square of the Ship that is closest to (0, 0), and the Ship's
orientation (either 'R' if its squares occupy the same row or 'C' if its squares occupy 
the same column).  

This method will set the elements of the array that the Ship occupies to hold the address of the Ship.  
If a Ship would not fit entirely on the Board, or if it would overlap any previously placed ships, 
the ship should not be added to the Board and the method should return false.  
Otherwise, the ship should be placed on the Board, the number of un-sunk ships should be incremented, 
and the method should return true.

9. a method called attack that takes as parameters the row and column of the attack (in that order).  
If the attack hits a Ship, you should: record the attack in the bool array.

If that square has not been hit before, you should call that Ship's takeHit method.

If all of a Ship's squares have been hit, you should print 
"They sank [insert name of ship here]!" and decrement the number of ships that remain un-sunk 
(you should only do these once for any ship) return true (even if that square was previously hit)

If the attack is not a hit, you should record the attack in the bool array and return false.

10. a method called allShipsSunk that returns true if all ships on the Board have been sunk, 
but returns false otherwise.
*********************************************************************/
#include <iostream>
#include "BBoard.hpp"
#include "Ship.hpp"

/************************************************
** Default Constructor
** Initializes each element of the boolArray to false 
** and each element of the Ship-pointer array to NULL.
*************************************************/
BBoard::BBoard() {
  this->numberOfUnsunkShips = 0;
  // Init attacksArray to false
  // Init occupiedByShip array
  for(int row = 0; row < 10; row++) {
    for(int col = 0; col < 10; col++) {
      this->attacksArray[row][col] = false;
      this->occupiedByShip[row][col] = NULL;
    }
  }
}

/************************************************
** getAttacksArrayElement
** takes a row and column (in that order) and 
** returns the element at that position of the 
** bool array.
*************************************************/
bool BBoard::getAttacksArrayElement(int row, int col) {
  return this->attacksArray[row][col];
}


/************************************************
** getShipsArrayElement
** takes a row and column (in that order) and 
** returns the element at that position of the 
** ships array.
*************************************************/
Ship* BBoard::getShipsArrayElement(int row, int col) {
  return this->occupiedByShip[row][col];
}


/************************************************
** getNumShipsRemaining
** returns how many ships remain un-sunk.
*************************************************/
int BBoard::getNumShipsRemaining() {
  return this->numberOfUnsunkShips;
}

/************************************************
** placeShip
** takes a Ship object, the row and column of the square of the 
** Ship that is closest to (0, 0), and the Ship's orientation
** (either 'R' if its squares occupy the same row or 'C' if 
** its squares occupy the same column).
** 
** This method will set the elements of the array that the 
** Ship occupies to hold the address of the Ship.
** 
** If a Ship would not fit entirely on the Board, or if it 
** would overlap any previously placed ships, the ship 
** should not be added to the Board and the method should 
** return false.
**   
** Otherwise, the ship should be placed on the Board, 
** the number of un-sunk ships should be incremented, 
** and the method should return true.
** The first parameter of placeShip shouldn't be a Ship object 
** (whether by value or by reference).  
** The first parameter should be a Ship-pointer.
*************************************************/
bool BBoard::placeShip(Ship* ship, int row, int col, char orientation) {
  // Init the bool value for recognizing if the Ship
  // can be placed in the place
  // Init the counter to record the number of Ships
  // have been placed

  bool shipCanBePlaced = false;
  int lengthOfShipsBePlaced = 0;

  // Check the boundry 
  // orientation = R: same row add length on col
  // orientation = C: same col add lenght on row
  if(orientation == 'R' 
     && col >= 0 && row >= 0
     && row < 10 && col + ship->getLength() - 1 < 10) {
       shipCanBePlaced = true;
       
  } else if(orientation == 'C' 
           && col >= 0 && row >= 0
           && col < 10 && row + ship->getLength() - 1 < 10) {
            shipCanBePlaced = true;
           }

  while(lengthOfShipsBePlaced < ship->getLength() 
        && shipCanBePlaced) {
          // Orientation = C(0,1) -> row ++
          // [][] [0][1] [][]
          // [][] [1][1] [][]
          // [][] [1][1] [][]
          // Orientation = R(0,0) -> col ++
          // [0][0] [0][1] [0][2]
          // [][] [][] [][]
          // [][] [][] [][]

          if(orientation == 'C' && 
          this->occupiedByShip[row][col] == NULL) {
            // Place the Ship, increas the lengthOfShipsBePlaced
            this->occupiedByShip[row][col] = ship;
            row++;
            lengthOfShipsBePlaced++;
          } else if(orientation == 'R' &&
                    this->occupiedByShip[row][col] == NULL) {
                      this->occupiedByShip[row][col] = ship;
                      col++;
                      lengthOfShipsBePlaced++;
          } else {
            shipCanBePlaced = false;
          }
    }

  // If successfully placed the ship, increase the 
  // numberOfUnsunkShips
  if(shipCanBePlaced) {
    numberOfUnsunkShips++;
  } 

  return shipCanBePlaced;
}



/************************************************
** attack
** takes as parameters the row and column of the attack 
** (in that order)
**
** Record the attack in the bool array
**
** If that square has not been hit before, you should call 
** that Ship's takeHit method.
**
** If all of a Ship's squares have been hit, you should print 
** "They sank [insert name of ship here]!" and decrement the 
** number of ships that remain un-sunk (you should only do 
** these once for any ship) return true (even if that square 
** was previously hit)
**
** If the attack is not a hit, you should record the attack
** in the bool array and return false.
*************************************************/
bool BBoard::attack(int row, int col) {
  // Init the Get the Ship
  Ship* currentShip = this->getShipsArrayElement(row, col);
  bool hasBeenHit = this->getAttacksArrayElement(row, col);

  // If Attack is not a hit 
  // Still record the attack on attacksArray
  if(!hasBeenHit && currentShip == NULL) {
    this->attacksArray[row][col] = true;
    return false;
  }

  // If the position has been hit before
  // return true (even if that square was previously hit)
  if(hasBeenHit && currentShip != NULL) {
    return true;
  } 

  // The Square has not been hit before
  // and it hit the Ship
  if(!hasBeenHit && currentShip != NULL) {  
    this->attacksArray[row][col] = true;
    // Call the Ship takeHit mehtod
    currentShip->takeHit();
    // All of a Ship's squares have been hit
    if(currentShip->getLength() == currentShip->getDamage()) {
      std::cout << "They sank " << currentShip->getName() << "!\n";
      this->numberOfUnsunkShips--;
    }
  }
  return true;
}


/************************************************
** allShipsSunk
** returns true if all ships on the Board have been sunk, 
** but returns false otherwise.
*************************************************/
bool BBoard::allShipsSunk() {
  return this->numberOfUnsunkShips == 0;
}

/************************************************
** printBoard
** Print the Current Board
** h: There is a Ship be attacked
** S: There is a Ship didn't be attacked
** a: There is an attack but miss the Ship
** -: Empty(No Ship). Nothing happened yet.
*************************************************/
void BBoard::printBoard() {
  std::cout << "  ";
  for(int i = 0; i < 10; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for(int row = 0; row < 10; row++) {
    std::cout << row << " ";
    for(int col = 0; col < 10; col++) {
      if(this->attacksArray[row][col] && this->occupiedByShip[row][col] != NULL) {
        std::cout << 'h' << " ";
      } else if(!this->attacksArray[row][col] && this->occupiedByShip[row][col] != NULL) {
        std::cout << 'S' << " ";  
      } else if(this->attacksArray[row][col] && this->occupiedByShip[row][col] == NULL) {
        std::cout << 'a' << " ";
      } else if (!this->attacksArray[row][col] && this->occupiedByShip[row][col] == NULL) {
        std::cout << '-' << " ";
      }
    }
    std::cout << std::endl;
  }
}
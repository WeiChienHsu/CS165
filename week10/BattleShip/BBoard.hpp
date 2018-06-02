/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         06/01/18
** Description:  a class called CFBoard that represents a game board for 
                 playing Connect Four (Links to an external site.)

The BBoard class represents a 10x10 grid that holds some number of Ships.  It should have:

a 10x10 array of bools (for keeping track of what squares have been attacked)
a 10x10 array of Ship-pointers (for keeping track of which Ships occupy which squares)
a variable that keeps track of the number of ships that remain un-sunk
a constructor that initializes each element of the boolArray to false and each element of the Ship-pointer array to NULL (or nullptr if you prefer)
a method called getAttacksArrayElement that takes a row and column (in that order) and returns the element at that position of the bool array
a method called getShipsArrayElement that takes a row and column (in that order) and returns the element at that position of the ships array
a method called getNumShipsRemaining that returns how many ships remain un-sunk
a method called placeShip that takes as parameters (in this order): a Ship object, the row and column of the square of the Ship that is closest to (0, 0), and the Ship's orientation (either 'R' if its squares occupy the same row or 'C' if its squares occupy the same column).  I give a couple of examples at the end of the specifications.
This method will set the elements of the array that the Ship occupies to hold the address of the Ship.  If a Ship would not fit entirely on the Board, or if it would overlap any previously placed ships, the ship should not be added to the Board and the method should return false.  Otherwise, the ship should be placed on the Board, the number of un-sunk ships should be incremented, and the method should return true.

a method called attack that takes as parameters the row and column of the attack (in that order).  If the attack hits a Ship, you should:
record the attack in the bool array
if that square has not been hit before, you should call that Ship's takeHit method
if all of a Ship's squares have been hit, you should print "They sank [insert name of ship here]!" and decrement the number of ships that remain un-sunk (you should only do these once for any ship) 
return true (even if that square was previously hit)
If the attack is not a hit, you should record the attack in the bool array and return false.

a method called allShipsSunk that returns true if all ships on the Board have been sunk, but returns false otherwise.
*********************************************************************/
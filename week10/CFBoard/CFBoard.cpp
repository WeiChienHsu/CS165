/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         06/01/18
** Description:  a class called CFBoard that represents a game board for 
                 playing Connect Four (Links to an external site.)

  1. a 7x6 array of char as a data member, which will store the locations of the players' pieces.

  2. a variable called gameState that holds one of the four following values:
     X_WON, O_WON, DRAW, or UNFINISHED - use an enum type for this, not string 
     (the enum definition should go in CFBoard.hpp, before the class, not inside it).

  3. a default constructor that initializes all elements of the array to being empty 
     (you can use whatever character you want to represent that a square is empty) 
     and initializes the gameState to UNFINISHED. 

  4. a method called "makeMove" that takes the column of the move 
     (1-7, see the example below) and which player's turn it is ('x' or 'o') as parameters.  
     
     If the gameState is not UNFINISHED, or the selected column is already full, 
     then makeMove should just return false.  
     
     Otherwise, makeMove should record the move, call the updateGameState 
     method (described next), and return true.  
     
     The piece that is played should "fall" to the "lowest" unoccupied square of that column 
     (see the example below).

  5. a method called updateGameState.  
     This method takes the array indices of the piece that was just played and updates the gameState 
     if the game has now been won or drawn.  
     
     The first parameter will be a row index (0-5) and the second parameter will be a column index (0-6).  
     
     The game has been won when either player has four pieces in a row either orthogonally or diagonally.  
     The game has been drawn when the board is completely full and neither player has won. 

     Since this method is just for internal use, it would normally be private, 
     but I want you to make it "public" so I can test it separately.   

  6. a method called getGameState that just returns the value of gameState.
  7. optional: a method called print, which just prints out the current board to the screen - this is not required, 
     but will very likely be useful for debugging.
*********************************************************************/
#include <iostream>
#include "CFBoard.hpp"
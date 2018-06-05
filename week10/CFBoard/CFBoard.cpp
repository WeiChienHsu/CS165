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


/*********************************************************************
** CFBoard()
** initializes all elements of the array to being empty.
** initializes the gameState to UNFINISHED.
*********************************************************************/
CFBoard::CFBoard() {
  // initialize all element
  for(int row = 0; row < 6; row++) {
    for(int col = 0; col < 7; col++) {
      this->playerBoard[row][col] = 'e';
    }
  }
  this->currentGameState = UNFINISHED;
}

/*********************************************************************
** CFBoard(char playBoard[6][7])
** For testing, initlized the playerBoard by passed mock game
*********************************************************************/
CFBoard::CFBoard(char mockPlayerBoard[6][7]) {
  for(int row = 0; row < 6; row++) {
    for(int col = 0; col < 7; col++) {
      this->playerBoard[row][col] = mockPlayerBoard[row][col];
    }
  }
  this->currentGameState = UNFINISHED;
}

/*********************************************************************
** makeMove()
** Takes the column of the move and which player's turn it is ('x' or 'o') as parameters.  
** If the gameState is not UNFINISHED, or the selected column is already full, 
** then makeMove should just return false. 
**
** Otherwise, makeMove should record the move, call the updateGameState 
** method and return true.  
*********************************************************************/
bool CFBoard::makeMove(int col, char player) {
  // Modify the column
  int actualCol = col - 1;
  // Check if the game is unfinished
  if(this->currentGameState != UNFINISHED) return false;
  // Check if the column is full (board[0][col] have been assigned)
  if(this->playerBoard[0][actualCol] != 'e') return false;

  // Place player's piece
  int row = 0;
  while(this->playerBoard[row][actualCol] == 'e'
        && row < 6) {
    row++;
  } 

  // Assign the player choice into playerBoard
  this->playerBoard[row - 1][actualCol] = player;
  
  // Update GameState
  updateGameState(row - 1, actualCol);
  return true;

}

/*********************************************************************
** updateGameState
** The first parameter will be a row index (0-5) and the second parameter 
** will be a column index (0-6).  
** The game has been won when either player has four pieces in a row 
** either orthogonally or diagonally.  
** The game has been drawn when the board is completely full and neither 
** player has won.
*********************************************************************/
void CFBoard::updateGameState(int row, int col){
  // Test each line by using DFSSearch function
  bool haveAWinner = false;
  char currentSign = this->playerBoard[row][col];

  if(DFSSearch(row, col, 0, 1) ||
     DFSSearch(row, col, 1, 0) ||
     DFSSearch(row, col, 1, 1) ||
     DFSSearch(row, col, 1, -1)
  ) {
    haveAWinner = true;
  }

  // Check the Winner
  if(haveAWinner) {
    if(currentSign == 'x') {
      this->currentGameState = X_WON;
    } else {
      this->currentGameState = O_WON;
    }
  } else if(isFull()) {
      this->currentGameState = DRAW;
  }
  
}

/*********************************************************************
** getGameState
** returns the value of gameState.
*********************************************************************/
GameStates CFBoard::getGameState() {
  return this->currentGameState;
}

/*********************************************************************
** print
** prints out the current board to the screen 
*********************************************************************/
void CFBoard::print() {

  // Preint 1 - 7 numbers
  for(int i = 1; i <= 7; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  
  // Print whole board
  for(int row = 0; row < 6; row++) {
    for(int col = 0; col < 7; col++) {
      std::cout << this->playerBoard[row][col] << " ";
    }
    std::cout << std::endl;
  }

}

/*********************************************************************
** printGameState
** Print value of GameStates
*********************************************************************/
void CFBoard::printGameState() {
  switch(this->currentGameState) {
    case 0:
      std::cout << "X won the game";
      break;
    case 1:
      std::cout << "O won the game";
      break;
    case 2:
      std::cout << "Tied";
      break;
    case 3:
      std::cout << "Unfinished";
      break;  
  }
  std::cout << std::endl;
}

/*********************************************************************
** isFull
** To check if the current board is full (only have 'o' and 'x')
*********************************************************************/
bool CFBoard::isFull() {
  for(int row = 0; row < 6; row ++) {
    for(int col = 0; col < 7; col++) {
      if(this->playerBoard[row][col] == 'e') {
        return false;
      }
    }
  }
  return true;
}

/*********************************************************************
** DFSSearch
** Search four direction of the passed rol and col
** If there is more than 4 connected same charactor
** Return ture, if not return false
** Ex:
** [0][0] [0][1] [0][2]
** [1][0] [1][1] [1][2]
** [2][0] [2][1] [2][2]
**               r  c
** left - right  0  1
** upper - down  1  0
** diagonally(/) 1 -1
** diagonally(\) 1  1
*********************************************************************/
bool CFBoard::DFSSearch(int row, int col, int rowNext, int colNext) {
  // In order to check the opposite direction
  // We init the metDifferentSign as false
  // While searching on the borad, if we met the different sign
  // stop searching and when we start an opposite direction searching
  // chagne the value back to false
  bool metDifferentSign = false;
  char currentSign = this->playerBoard[row][col];
  int count = 1;

  // Set newRow and newCol to the next one we want to check
  int newRow = row + rowNext;
  int newCol = col + colNext;

  // Check the boundry (Valid number and consecutive sign)
  while(newRow >= 0 && newCol >= 0 && newRow < 6 && newCol < 7 && !metDifferentSign) {
    if(this->playerBoard[newRow][newCol] == currentSign) {
      count++;
    } else {
      metDifferentSign = true;
    }
    // Update the next one
    newRow += rowNext;
    newCol += colNext;
  }

  // Check the opposite direction
  newRow = row - rowNext;
  newCol = col - colNext;
  metDifferentSign = false;
  
  // Check the boundry (Valid number and consecutive sign)
  while(newRow >= 0 && newCol >= 0 && newRow < 6 && newCol < 7 && !metDifferentSign) {
    if(this->playerBoard[newRow][newCol] == currentSign) {
      count++;
    } else {
      metDifferentSign = true;
    }
    // Update the next one
    newRow -= rowNext;
    newCol -= colNext;
  }

  if(count >= 4) {
    return true;
  } else {
    return false;
  }

}
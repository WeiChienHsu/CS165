/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/08/18
** Description:  User input the Graph they would like to draw, whether square or rectangles
                 Then input the numbers of grpah and the sides of it.
                 Program will output the numbers of the graph.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void drawRectangles(int number, int side) {
    for(int i = 0; i < number; i++) {
      cout << "+-----+" << endl;
      for(int j = 0; j < side; j++) {
        cout << "|     |" << endl;
      } 
      cout << "+-----+" << endl;
    } 
}

void drawSquare(int time, int side) {

  while(time > 0) {
    
    // Build up All Sides
    string upperAndBottomSide = "+";
    string leftAndRightSide = "|";
    for(int i = 0; i < side; i++) {
      upperAndBottomSide.append("--");
      leftAndRightSide.append("  ");
    }
    upperAndBottomSide.append("+");
    leftAndRightSide.append("|");
    
    // Print the upper side
    cout << upperAndBottomSide << endl;

    // Print the right and left side
    for(int j = 0; j < side; j++) {
      cout << leftAndRightSide << endl;
    }

    // Print the upper side
    cout << upperAndBottomSide << endl;
    time--;
  }

}

void checkInput() {
  int numberOfRect;
  int side;
  int input;

  cout << "Please enter the graph to would like to draw(1: rectangles / 0: square):  " << endl;
  cin >> input;
  if(input == 1) {
      cout << "Please enter the number of rectangles: " << endl;
      cin >> numberOfRect;
      cout << "Please enter the side for each rectangles: " << endl;
      cin >> side;
      drawRectangles(numberOfRect, side);
  } else if(input == 0) {
      cout << "Please enter the number of Square: " << endl;
      cin >> numberOfRect;
      cout << "Please enter the side for each Square: " << endl;
      cin >> side;
      drawSquare(numberOfRect, side);
  } else {
    cout << "Please enter only 1 or 0.";
    checkInput();
  }
}

int main() {
  checkInput();
  return 0;
}


/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  Program prompts the user for an integer that the player
                 If the player's guess is higher than the target number, 
                 the program should display "too high"  If the user's guess 
                 is lower than the target number, the program should display 
                 "too low".

                 The program should use a loop that repeats until the user correctly 
                 guesses the number.  Then the program should print how many guesses 
                 it took. 
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
    int count = 0, targetNumber, guessNumber;
    bool userIsRight = false;

    // Assign a target number for user to guess
    cout << "Enter the number for the player to guess." << endl;
    cin >> targetNumber;

    cout << "Enter your guess." << endl;
    
    // While user don't gusee a right number, we will keep asking them to enter new number
    while(!userIsRight) {
      // Count how many number user enters
      cin >> guessNumber;
      count++;

      if(guessNumber == targetNumber) {
        // If user is correct, change the status of guessing and print out the count
        userIsRight = true;
        cout << "You guessed it in " << count << " tries." << endl;
      } else if (guessNumber > targetNumber) {
        cout << "Too high - try again." << endl;
      } else {
        cout << "Too low - try again." << endl;
      }
    }

    return 0;
}
/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/08/18
** Description:  User input numbers to guess the random numbers, and program
                 will limit user only could guess five times.
                 - Practice : rand() / srand() / exit() -> cstdlib
                 - Practice : differet between srand() and rand()
                 - Practice: time() -> time.h (In order to srand() to Set a Seed for rand())
*********************************************************************/

#include <iostream>
#include <cstdlib> // srand(), rand(), exit()
#include <time.h> // time() 
using namespace std;

int main() {

  int randomNumber;
  int guessTime = 5;
  int guessNumber;

  srand(time(NULL));

  randomNumber = rand() % 20 + 1;
  
  while(guessTime > 0) {
    cout << "Please Input your guess(from 1 - 20): " << endl;
    guessTime--;

    cin >> guessNumber;
    if(guessNumber == randomNumber) {
      cout << "Correct! You're right! " << endl;
      exit(0);
    } else {
        cout << "Try Again, you still have " << guessTime << " times to guess." << endl;
        guessNumber > randomNumber?
           cout << "Your number is greater than the TARGET!" << endl:
           cout << "Your number is smaller than the TARGET!" << endl;
           cout << "############################" << endl;
      }
    }

  cout << "Sorry! You've done a great job, the answer is: " << randomNumber << endl;
  return 0;
}
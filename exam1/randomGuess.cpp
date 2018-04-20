#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
  int randomNumber, userGuess = 0, guessNumber = 0;
  std::srand((unsigned)time(NULL));
  randomNumber = ((int)std::rand() % 10) + 1;

  while(guessNumber != randomNumber) {
    std::cout << "Enter your guess: " << std::endl;
    std::cin >> guessNumber;

    if(guessNumber > randomNumber) {
      std::cout << "Too high - try again." << std::endl;
    }

    if(guessNumber < randomNumber) {
      std::cout << "Too low - try again." << std::endl;
    }
    userGuess++;
  }


  std::cout << "You guessed it in " << userGuess << " tries." << std::endl;
  return 0;
}
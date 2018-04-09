/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Asks the user enters score, and Output the grade sceciton
                 by default.
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
  const int MIN_A_SECTION = 90,
            MIN_B_SECTION = 70,
            MIN_C_SECTION = 50,
            MIN_POSSIBLE = 0;
  
  int score;
  char grade;

  cout << "Please enter your score: " << endl;
  cin >> score;

  while(score < MIN_POSSIBLE) {
    cout << "Please enter a score greater than 0!" << endl;
    cin >> score;
  }

  if(score >= MIN_A_SECTION) {
      grade = 'A';
  } else if (score >= MIN_B_SECTION) {
      grade = 'B';
  } else if(score >= MIN_C_SECTION) {
      grade = 'C';
  } else {
      grade = 'D';
  }

  cout << "Your score is in the Grade: " << grade << " Section." << endl;
  return 0;
}
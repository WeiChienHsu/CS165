/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  Program will get and validate how many numbers there are to choose from (n)
                 and how many of these number must be selected(k). Then, 
                 compute the number of ways a set of k items can be selected from 
                 a set of n items. Report to the user his or her chances of winning
                 and his probability of winning.
*********************************************************************/

// Print "This program... "
// Print "How many... n"
// User Input n (Valid Input (1 - 12))
// Print "How many... k"
// User Input k (Valid Input (1 - n))

// Count the totalNumber(int) by factorial(n) / (factorial(n - k) * factorial(k))
// Print "Your chance ... 1 chance in"  + totalNumber
// Count the posibility(float)
// Print posibility 

#include <iostream>
using namespace std;

int factorial(int num);
float countPosibility(int num);
int firstPick();
int validFirstPick();
int validSecondPick(int n);

int main() {
  int n, k, totalNumber;
  float posibility;

  cout << "This program could tell you your probability of winning!.\n";
  cout << "How much number(1-12) are there to pick form?\n ";
  n = validFirstPick();
  cout << "How many number must you pick to play? \n";
  k = validSecondPick(n);

  totalNumber = factorial(n) / (factorial(n - k) * factorial(k));
  cout << "Your chance of winning the lottery is 1 chance in " << totalNumber << " .\n";

  posibility = countPosibility(totalNumber);
  cout << "This is a probability of " << posibility << endl;
  return 0;
}

float countPosibility(int num) {
  return 1 / (float)num;
}

int factorial(int num) {
  int count = 1;
  int total = 1;
  while(count <= num) {
    total *= count++;
  }
  return total;
}

int validSecondPick(int n) {
  int k;
  cin >> k;
  while(k < 1 || k > n) {
    cout << "How many number must you pick to play? \n";
    cin >> k;
  }
  return k;
}

int validFirstPick() {
  int n;
  cin >> n;
  while(n < 1 || n >12) {
     cout << "How much number(1-12) are there to pick form?\n ";
     cin >> n;
  }
  return n;
}
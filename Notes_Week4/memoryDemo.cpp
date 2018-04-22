#include <iostream>
using namespace std;

int main() {
  int *pInt = 0;
  pInt = new int(28);
  pInt = new int(27);
  cout << *pInt << endl;
  delete pInt;


  return 0;
}
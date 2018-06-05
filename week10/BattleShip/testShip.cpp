#include "Ship.hpp"
#include <iostream>
using namespace std;
int main() {
  Ship shipA("Kevin", 4);
  cout << shipA.getDamage() << endl;
  cout << shipA.getLength() << endl;
  cout << shipA.getName() << endl;
  shipA.takeHit();
  cout << shipA.getDamage() << endl;
  return 0;
}
/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  Client Code, testing the Team and Player program. 
****************************************/

#include <iostream>
#include "Player.hpp"
#include "Team.hpp"
using namespace std;

int main() {
  Player p1("Charlotte", 24, 10, 7);
  Player p2("Emily", 21, 13, 9);
  Player p3("Anne", 20, 10, 8);
  Player p4("Jane", 19, 10, 10);
  Player p5("Mary", 18, 11, 8);
  if (p1.hasMorePointsThan(p4))
  cout << p1.getName() << " has more points than " << p4.getName() << "." << endl;
  p5.setRebounds(12);

  Team team1(p1, p2, p3, p4, p5);
asd
  // Player p = team1.getShootingGuard();
  // cout << p.getName() << endl;
  cout << team1.totalPoints() << endl;
}

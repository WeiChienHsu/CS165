/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The function definitions (implementation) for Team.              
                 Private Values: has five data members of type Player: 
                 a point guard, a shooting guard, a small forward, a power 
                 forward, and a center.
   
                 Implementaion:
                  Team(Player pg, Player sg, Player sf, Player pf, Player c):
                    The class should have a constructor that takes five Players 
                    and uses them to initialize each of those data members.
                    (in the given order).

                  It should have get methods for each data member and have set 
                  methods for each of the stats:

                  void setPointGuard
                  Player getPointGuard
                  void setShootingGuard
                  Player getShootingGuard
                  void setSmallForward
                  Player getSmallForward
                  void setPowerForward
                  Player getPowerForward
                  void setCenter
                  Player getCenter

                  int totalPoints() : returns the sum of the points for all 
                                  players on the team.
                                  team.getPointGuard().getPoints() +
                                  team.getShootingGuard().getPoints() +
                                  team.getSmallForward().getPoints() +
                                  team.getPowerForward().getPoints() +
                                  team.getCenter().getPoints()
*********************************************************************/

#include <iostream>
#include "Team.hpp"
#include "Player.hpp"

Team::Team(Player pg, Player sg, Player sf, Player pf, Player c) {
  setPointGuard(pg);
  setShootingGuard(sg);
  setSmallForward(sf);
  setPowerForward(pf);
  setCenter(c);
}
void Team::setPointGuard(Player pg) {
  PointGuard = pg;
}

Player Team::getPointGuard() {
  return PointGuard;
}

void Team::setShootingGuard(Player sg) {
  ShootingGuard = sg;

}
Player Team::getShootingGuard() {
  return ShootingGuard;
}

void Team::setSmallForward(Player sf) {
  SmallForward = sf;
}

Player Team::getSmallForward() {
  return SmallForward;
}

void Team::setPowerForward(Player pf)  {
  PowerForward = pf;
}

Player Team::getPowerForward() {
  return PowerForward;
}

void Team::setCenter(Player c) {
  Center = c;
}
Player Team::getCenter() {
  return Center;
}
int Team::totalPoints() {
  return getPointGuard().getPoints() +
  getShootingGuard().getPoints() +
  getSmallForward().getPoints() +
  getPowerForward().getPoints() +
  getCenter().getPoints();
}
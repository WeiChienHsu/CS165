/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The function definitions (implementation) for Player.              
                 Private Values: a string for the player's name, and an int 
                 for each of these stats: points, rebounds and assists. 

   
                 Implementaion:
                  Player() : a default constructor that initializes the 
                            name to the empty string ("") and initializes 
                            each of the stats to -100. (Need Setter functions)

                  Player(string name, int points, int rebounds, int assists) :
                    a constructor that takes four parameters and uses them to 
                    initialize the data members.

                  It should have get methods for each data member and have set 
                  methods for each of the stats:

                  string getName
                  void setPoints
                  int getPoints
                  void setRebounds
                  int getRebounds
                  void setAssists
                  int getAssists

                  hasMorePointsThan() : a bool method called hasMorePointsThan that 
                                      takes a Player parameter and returns true if the 
                                      Player that is executing the function has more points 
                                      than the Player that was passed as a parameter.  
                                      Otherwise it should return false. 
*********************************************************************/

#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

Player::Player() {
  name = "";
  setPoints(-100);
  setRebounds(-100);
  setAssists(-100);
}
Player::Player(string n, int p, int r, int a) {
  name = n;
  setPoints(p);
  setRebounds(r);
  setAssists(a);
}

string Player::getName() {
  return name;
}

void Player::setPoints(int p) {
  points = p;
}

int Player::getPoints() {
  return points;
}

void Player::setRebounds(int r) {
  rebounds = r;
}

int Player::getRebounds() {
  return rebounds;
}

void Player::setAssists(int a) {
  assists = a;
}

int Player::getAssists() {
  return assists;
}

bool Player::hasMorePointsThan(Player newPlayer) {
  if(getPoints() > newPlayer.getPoints()) {
    return true;
  } else {
    return false;
  }
}
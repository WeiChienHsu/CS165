/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         06/01/18
** Description:  a class called CFBoard that represents a game board for 
                 playing Connect Four (Links to an external site.)

The Ship class represents a ship that has:

a name (e.g. "my destroyer", "my submarine", "Boaty McBoatface")
a length (the number of squares it occupies)
a damage (how many of its squares have been hit)
a constructor that takes as parameters (in this order): the Ship's name and the Ship's length, which will be used to initialize the corresponding data members.  The damage should be initialized to zero.
getMethods for each data member (getName, getLength, getDamage)
a method called takeHit that increments a Ship's damage by one

*********************************************************************/
#ifndef SHIP_HPP
#define SHIP_HPP
#include <string>

class Ship {
  private:
    std::string name;
    int length;
    int damage;

  public:
    Ship(std::string, int);
    std::string getName();
    int getLength();
    int getDamage();
    void takeHit();
};


#endif
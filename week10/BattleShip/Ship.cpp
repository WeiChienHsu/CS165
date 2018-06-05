/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         06/01/18
** Description:  a class called CFBoard that represents a game board for 
                 playing Connect Four (Links to an external site.)

The Ship class represents a ship that has:

a name (e.g. "my destroyer", "my submarine", "Boaty McBoatface")
a length (the number of squares it occupies)
a damage (how many of its squares have been hit)

a constructor that takes as parameters (in this order): 
the Ship's name and the Ship's length, which will be used 
to initialize the corresponding data members.  
The damage should be initialized to zero.

getMethods for each data member. (getName, getLength, getDamage)

a method called takeHit that increments a Ship's damage by one.

*********************************************************************/
#include <iostream>
#include <string>

/*********************************************************
** Default Constructor
** initialize the corresponding data members.  
** The damage should be initialized to zero.
**********************************************************/
Ship::Ship(std::string name, int l) {
  this->name = name;
  this->length = l;
  this->damage = 0;
}

/*********************************************************
** getName
** return the name
**********************************************************/
std::string getName() {
  return this->name;
}

/*********************************************************
** getLength
** return the length
**********************************************************/
int Ship::getLength() {
  return this->length;
}

/*********************************************************
** getDamage
** return the damage
**********************************************************/
int Ship::getDamage() {
  return this->damage;
}

/*********************************************************
** takeHit
** increments a Ship's damage by one.
**********************************************************/
void Ship::takeHit() {
  this->damage++;
}


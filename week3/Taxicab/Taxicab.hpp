/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The class declaration (interface) for Taxicab. 
                  (Don't need to implement here.)
                  :3 int fields called xCoord, yCoord and totalDistance.
                  :A default constructor
                  :2 parameter constructor that takes two int.
                  :3 getter functions return int.
                  :a method that change the value of xCoord and totalDistance
                  :a method that change the value of yCoord and totalDistance
*********************************************************************/

#ifndef TAXICAB_HPP
#define TAXICAB_HPP

class Taxicab {
  private:
    int xCoord;
    int yCoord;
    int totalDistance;

  public:
    Taxicab();
    Taxicab(int,int);
    int getXCoord();
    int getYCoord();
    int getDistanceTraveled();
    void moveX(int);
    void moveY(int);
};
#endif

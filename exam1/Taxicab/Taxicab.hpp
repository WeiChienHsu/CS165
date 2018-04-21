#ifndef TAXICAB_HPP
#define TAXICAB_HPP

class Taxicab {
  private:
    int coordX;
    int coordY;
    int totalDistance;
  public:
    Taxicab();
    Taxicab(int, int);
    void moveX(int);
    void moveY(int);
    int getDistanceTraveled();
    int getXCoord();
    int getYCoord();
};

#endif
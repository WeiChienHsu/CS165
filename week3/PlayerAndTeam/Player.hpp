/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The class declaration (interface) for Player. 
                  (Don't need to implement here.)
                  :string name, int points, int rebounds, int assists
                  :A default constructor
                  :4 parameter constructor that takes one string and three int.
                  string getName
                  void setPoints
                  int getPoints
                  void setRebounds
                  int getRebounds
                  void setAssists
                  int getAssists
                  bool hasMorePointsThan
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
  private:
    std::string name;
    int points;
    int rebounds;
    int assists;
  public:
    Player();
    Player(std::string, int, int, int);
    std::string getName();
    void setPoints(int);
    int getPoints();
    void setRebounds(int);
    int getRebounds();
    void setAssists(int);
    int getAssists();
    bool hasMorePointsThan(Player);
};

#endif

/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/14/18
** Description:  The class declaration (interface) for Team. 
                  (Don't need to implement here.)
                  :5 Player Objects
                  :5 parameter constructor that takes all Player Objects.
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
                    int totalPoints() 

*********************************************************************/
#ifndef TEAM_HPP
#define TEAM_HPP
#include "Player.hpp"

class Team {
  private:
    Player PointGuard;
    Player ShootingGuard;
    Player SmallForward;
    Player PowerForward;
    Player Center;
    
  public:
    Team(Player, Player, Player, Player, Player);
    void setPointGuard(Player);
    Player getPointGuard();
    void setShootingGuard(Player);
    Player getShootingGuard();
    void setSmallForward(Player);
    Player getSmallForward();
    void setPowerForward(Player);
    Player getPowerForward();
    void setCenter(Player);
    Player getCenter();
    int totalPoints(); 
};

#endif

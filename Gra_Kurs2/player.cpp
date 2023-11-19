#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "player.h"

class Player 
{
public:
    std::string name = "Hero";
    
    PlayerStats player;
    int getPlayerLife(){
     return player.hp;
    }

    int getPlayerStrenght(){
      return player.strenght;
    }
    
    int getPlayerDefence(){
      return player.defence;
    }
};
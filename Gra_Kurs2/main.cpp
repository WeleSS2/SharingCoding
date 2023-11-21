/*
    Gra
    Jest 1 gracz.
    Sa dwie lokacje.
    I sa dwa rodzaje mobow.
    Gracz walczy z mobami w tych dwoch lokacjach.
*/
// W klasach i strukturach
// Zmienne -> Polami
// Funkcje -> Metodami

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "locations.h"

// Typ | Nazwe     |  Liste parametrow (deklaracja),{definicja}
void function();    /// deklracja
void function2(){}; // definicja

void function(){

};

struct PlayerStats
{
  int hp = 200;
  int strength = 45;
  int defence = 55;
};

class Player
{
public:
  std::string name = "Hero";

  PlayerStats player;
  int getPlayerLife()
  {
    return player.hp;
  }

  int getPlayerStrenght()
  {
    return player.strength;
  }

  int getPlayerDefence()
  {
    return player.defence;
  }
};

int main()
{
  srand(time(NULL));

  ForestData forest;
  DungeonData dungeon;
  HillData hill;

  Player newPlayer;
  Forest forest1;
  Dungeon dungeon1;
  Hill hill1;

  // forest1.showLocation(forest1.getLocationDescription(), forest1.getLocationName());
  // forest1.generateMobs(forest1.getMobTypes(), 3);
  dungeon1.generateMobs(dungeon1.getMobTypes(), 3);
  // hill1.generateMobs(hill1.getMobTypes(), 3);
  // std::cout << forest1.applyDefenceModifier(forest.defMod, newPlayer.player.defence) << "\n";

  // dungeon1.showLocation(dungeon1.getLocationDescription(), dungeon1.getLocationName());
  // hill1.showLocation(hill1.getLocationDescription(), hill1.getLocationName());

  // std::cout << hill1.applyStrengthModifier(hill.strMod, newPlayer.player.strength) << "\n";

  return 0;
}

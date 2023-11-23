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
#include "mobs.h"

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

enum GameLocations
{
  FOREST = 0,
  DUNGEON = 1,
  HILL = 2
};

void createRandomLocation(Player &player, GameLocations location);
void mobSpawn(char *mobCollection);

void mobSpawn(char *mobCollection)
{
  int len = 0;

  // Calculate the length of the array by iterating until the null character is found
  for (size_t i = 0; mobCollection[i] != '\0'; i++)
  {
    len++;
  }

  for (size_t i = 0; i < len; i++)
  {
    switch (mobCollection[i])
    {
    case 'g':
    {
      std::cout << "Goblin Attack \n";
    }
    break;
    case 'o':
    {
      std::cout << "Orc Charge \n";
    }
    break;
    case 'd':
    {
      std::cout << "Dragon Destroy\n";
    }
    break;

    default:
      std::cout << "We running out of monsters. Please come back later!\n";
      break;
    }
  }
}

void createRandomLocation(Player &player, GameLocations location)
{

  switch (location)
  {
  case FOREST:
  {
    // create a location
    Forest forest;
    // show location description
    forest.showLocation(forest.getLocationDescription(), forest.getLocationName());

    // apply terrain modifications
    forest.applyDefenceModifier(forest.forestLocation.defMod, player.player.defence);
    forest.applyStrengthModifier(forest.forestLocation.strMod, player.player.strength);

    // generate random mobs, we can specify numbers of generated mobs
    forest.generateMobs(forest.getMobTypes(), 3);
    mobSpawn(forest.pMobsArray);

    // unallocate mobsArray from memory to avoid memory leaks.
    delete[] forest.pMobsArray;
  }
  break;
  case DUNGEON:
  {
    // create a location
    Dungeon dungeon;
    // show location description
    dungeon.showLocation(dungeon.getLocationDescription(), dungeon.getLocationName());

    // apply terrain modifications
    dungeon.applyDefenceModifier(dungeon.dungeonLocation.defMod, player.player.defence);
    dungeon.applyStrengthModifier(dungeon.dungeonLocation.strMod, player.player.strength);

    // generate random mobs, we can specify numbers of generated mobs
    dungeon.generateMobs(dungeon.getMobTypes(), 3);
    mobSpawn(dungeon.pMobsArray);

    // unallocate mobsArray from memory to avoid memory leaks.
    delete[] dungeon.pMobsArray;
  }
  break;
  case HILL:
  {
    // create a location
    Hill hill;
    // show location description
    hill.showLocation(hill.getLocationDescription(), hill.getLocationName());

    // apply terrain modifications
    hill.applyDefenceModifier(hill.hillLocation.defMod, player.player.defence);
    hill.applyStrengthModifier(hill.hillLocation.strMod, player.player.strength);

    // generate random mobs, we can specify numbers of generated mobs
    hill.generateMobs(hill.getMobTypes(), 3);
    mobSpawn(hill.pMobsArray);

    // unallocate mobsArray from memory to avoid memory leaks.
    delete[] hill.pMobsArray;
  }
  break;

  default:
    break;
  }
}

int main()
{
  srand(time(NULL));

  Player newPlayer;

  // createRandomLocation(newPlayer, FOREST);

  // createRandomLocation(newPlayer, DUNGEON);

  createRandomLocation(newPlayer, HILL);
  return 0;
}

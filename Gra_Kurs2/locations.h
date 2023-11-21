#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "player.h"
#include "mobs.h"

struct ForestData
{
  int defMod{-5};
  int strMod{-2};
};

struct DungeonData
{
  int defMod{-10};
  int strMod{-5};
};

struct HillData
{
  int defMod{10};
  int strMod{5};
};

class Location
{

public:
  // create a null pointer
  std::string *pMobsArray = nullptr;
  void showLocation(std::string description, std::string locationName)
  {
    std::cout << "********************************************\n";
    std::cout << "*                                          *\n";
    std::cout << "        You entered " << locationName << "  \n";
    std::cout << "*                                          *\n";
    std::cout << "********************************************\n";

    std::cout << description << '\n';
  }

  int applyDefenceModifier(int defMod, int &playerDefence)
  {
    std::cout << "You received an area defence modifier : " << defMod << '\n';
    std::cout << "Player defence : ";
    return playerDefence += defMod;
  }

  int applyStrengthModifier(int strMod, int &playerStrength)
  {
    std::cout << "You received an area strength modifier : " << strMod << '\n';
    std::cout << "Player strength : ";
    return playerStrength += strMod;
  }

  void generateMobs(std::vector<std::string> mobTypes, unsigned short int number)
  {
    unsigned short int mobNumbers;
    mobNumbers = rand() % number + 1;

       // dynamic memory allocation
    pMobsArray = new std::string[number];

    for (size_t i = 0; i < number; i++)
    {
      std::cout << "Generate monster # " << i + 1 << '\n';
      unsigned short int randomIndex = rand() % mobTypes.size();
      pMobsArray[mobNumbers] = mobTypes[randomIndex];

      std::cout << pMobsArray[mobNumbers] << '\n';
    }
  }
};

// class Forest inherit from Locations
class Forest : public Location
{

public:
  std::string getLocationName() { return locationName; }
  std::string getLocationDescription() { return locationDescription; }
  std::vector<std::string> getMobTypes() { return mobTypes; }

private:
  std::string locationDescription = "The Dark Forest emerges ominously, its ancient trees stretching towards the heavens like gnarled fingers reaching for unwary travelers.\n"
                                    "Shadows dance among the dense undergrowth, whispered secrets lurking within its depths, inviting both danger and intrigue.";
  std::string locationName = "The Dark Forest";
  std::vector<std::string> mobTypes = {"orc", "goblin"};
};

// class Dungeon inherit from Locations
class Dungeon : public Location
{

public:
  std::string getLocationName() { return locationName; }
  std::string getLocationDescription() { return locationDescription; }
  std::vector<std::string> getMobTypes() { return mobTypes; }

private:
  std::string locationDescription = "The Dreadful Dungeon looms before you, its entrance swallowed by darkness and echoes of tormented souls.\n"
                                    "Within its cold, stone walls, a chilling aura of despair and forgotten horrors beckon for those brave enough to uncover its secrets.";
  std::string locationName = "The Dreadful Dungeon";
  std::vector<std::string> mobTypes = {"dragon", "orc", "goblin"};
};

// class Hill inherit from Locations
class Hill : public Location
{

public:
  std::string getLocationName() { return locationName; }
  std::string getLocationDescription() { return locationDescription; }
  std::vector<std::string> getMobTypes() { return mobTypes; }

private:
  std::string locationDescription = "The Highland Hill emerges majestically, its peak crowned with lush greenery and kissed by the gentle caress of a warm breeze.\n"
                                    "From its vantage point, a breathtaking vista unfolds, revealing rolling hills, cascading waterfalls, and a serene landscape that inspires awe and tranquility.";
  std::string locationName = "The Highland Hill";
  std::vector<std::string> mobTypes = {"goblin"};
};

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "player.h"

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
  // Pointer to an array of mobs in the location
  char *pMobsArray = nullptr;

  // Display the location name and description
  void showLocation(std::string description, std::string locationName)
  {
    std::cout << "********************************************\n";
    std::cout << "*                                          *\n";
    std::cout << "        You entered " << locationName << "  \n";
    std::cout << "*                                          *\n";
    std::cout << "********************************************\n";

    std::cout << description << '\n';
  }

  // Apply a defense modifier to the player's defense value
  int applyDefenceModifier(int defMod, int &playerDefence)
  {
    std::cout << "You received an area defence modifier : " << defMod << '\n';
    std::cout << "Current Player defence : " << playerDefence << '\n';
    return playerDefence += defMod;
  }

  // Apply a strength modifier to the player's strength value
  int applyStrengthModifier(int strMod, int &playerStrength)
  {
    std::cout << "You received an area strength modifier : " << strMod << '\n';
    std::cout << "Current Player strength : " << playerStrength << '\n';
    return playerStrength += strMod;
  }

  // Generate mobs in the location
  void generateMobs(std::vector<char> mobTypes, unsigned short int number)
  {
    unsigned short int mobNumbers;
    mobNumbers = rand() % number + 1; // add one space for '\0'

    // Dynamically allocate memory for the mob array
    // Need to remember to unallocate later!
    pMobsArray = new char[mobNumbers + 1];
    std::cout << mobNumbers;

    for (size_t i = 0; i < mobNumbers; i++)
    {
      std::cout << "Generate monster # " << i + 1 << '\n';
      unsigned short int randomIndex = rand() % mobTypes.size();

      pMobsArray[i] = mobTypes[randomIndex];
    }
    pMobsArray[mobNumbers] = '\0'; // null-terminate the array
  }
};

// class Forest inherit from Locations
class Forest : public Location

{
public:
  ForestData forestLocation;

  // Get the name of the forest location
  std::string getLocationName()
  {
    return locationName;
  }
  // Get the description of the forest location
  std::string getLocationDescription()
  {
    return locationDescription;
  }
  // Get the types of mobs in the forest location
  std::vector<char> getMobTypes()
  {
    return mobTypes;
  }

private:
  std::string locationDescription = "The Dark Forest emerges ominously, its ancient trees stretching towards the heavens like gnarled fingers reaching for unwary travelers.\n"
                                    "Shadows dance among the dense undergrowth, whispered secrets lurking within its depths, inviting both danger and intrigue.";
  std::string locationName = "The Dark Forest";
  std::vector<char> mobTypes = {'o', 'g'};
};

// class Dungeon inherit from Locations
class Dungeon : public Location

{
public:
  DungeonData dungeonLocation;
  std::string getLocationName() { return locationName; }
  std::string getLocationDescription() { return locationDescription; }
  std::vector<char> getMobTypes() { return mobTypes; }

private:
  std::string locationDescription = "The Dreadful Dungeon looms before you, its entrance swallowed by darkness and echoes of tormented souls.\n"
                                    "Within its cold, stone walls, a chilling aura of despair and forgotten horrors beckon for those brave enough to uncover its secrets.";
  std::string locationName = "The Dreadful Dungeon";
  std::vector<char> mobTypes = {'d', 'o', 'g'};
};

// class Hill inherit from Locations
class Hill : public Location

{
public:
  HillData hillLocation;
  std::string getLocationName() { return locationName; }
  std::string getLocationDescription() { return locationDescription; }
  std::vector<char> getMobTypes() { return mobTypes; }

private:
  std::string locationDescription = "The Highland Hill emerges majestically, its peak crowned with lush greenery and kissed by the gentle caress of a warm breeze.\n"
                                    "From its vantage point, a breathtaking vista unfolds, revealing rolling hills, cascading waterfalls, and a serene landscape that inspires awe and tranquility.";
  std::string locationName = "The Highland Hill";
  std::vector<char> mobTypes = {'g'};
};

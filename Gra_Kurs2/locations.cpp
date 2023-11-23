#include "locations.h"

//  // Display the location name and description
// void Location::showLocation(std::string description, std::string locationName)
// {
//     std::cout << "********************************************\n";
//     std::cout << "*                                          *\n";
//     std::cout << "        You entered " << locationName << "  \n";
//     std::cout << "*                                          *\n";
//     std::cout << "********************************************\n";
 
//     std::cout << description << '\n';
// }

//  // Apply a defense modifier to the player's defense value
//   int Location::applyDefenceModifier(int defMod, int &playerDefence)
//   {
//     std::cout << "You received an area defence modifier : " << defMod << '\n';
//     std::cout << "Current Player defence : " << playerDefence << '\n';
//     return playerDefence += defMod;
//   }

//     // Apply a strength modifier to the player's strength value
//   int Location::applyStrengthModifier(int strMod, int &playerStrength)
//   {
//     std::cout << "You received an area strength modifier : " << strMod << '\n';
//     std::cout << "Current Player strength : " << playerStrength << '\n';
//     return playerStrength += strMod;
//   }

//    // Generate mobs in the location
//   void Location::generateMobs(std::vector<char> mobTypes, unsigned short int number)
//   {
//     unsigned short int mobNumbers;
//     mobNumbers = rand() % number + 1; // add one space for '\0'

//     // Dynamically allocate memory for the mob array
//     // Need to remember to unallocate later!
//     pMobsArray = new char[mobNumbers + 1];
//     std::cout << mobNumbers;

//     for (size_t i = 0; i < mobNumbers; i++)
//     {
//       std::cout << "Generate monster # " << i + 1 << '\n';
//       unsigned short int randomIndex = rand() % mobTypes.size();

//       pMobsArray[i] = mobTypes[randomIndex];
//     }
//     pMobsArray[mobNumbers] = '\0'; // null-terminate the array
//   }
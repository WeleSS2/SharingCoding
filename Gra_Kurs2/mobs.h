#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "player.h"


struct GoblinStats
{
    std::string name = "Orc";
    int hp = 20;
    int strength = 5; 
    int defence = 1;
};

struct OrcStats
{
    std::string name = "Orc";
    int hp = 20;
    int strength = 5; 
    int defence = 1;
};

struct DragonStats
{
    std::string name = "Dragon";
    int hp = 800;
    int strength = 100; 
    int defence = 100;
    int level = 90;
};

class Dragon
{
public:
    char attackRandomize();

    std::string dialogue();

    void attack(char attackType, int &playerHealth);
private:
    std::vector<std::string> dialogueSentences = {"Arghhh!", "I'm going to eat you!", "Your going to be my dinner!"};
    
    std::vector<char> attackTypes = {'s', 'c', 't'}; 
    
    std::vector<std::string> attackName = {"Dragon throws fire at you!", "Dragon claws you!", "Dragon bites you!"};    
};

class Orc
{
public:
    char attackRandomize();

    std::string dialogue();

    void attack(char attackType, int &playerHealth);

private:
    
    int helpme = 0;
    
    OrcStats statsOrc;
    
    std::vector<std::string> dialogueSentences = {"You challenge me to a fight? ",  "Watch out for my moves! I dance with blades!", "Dance all you want. I\'m crush you!" };
    
    std::vector<char> attackTypes = {'s', 'f', 'k'}; 
    
    std::vector<std::string> attackName = {"Orc slash you with his axe!", "Orc hits you with his fist!", "Orc kicks you!"};
};

class Goblin
{
public:

    GoblinStats statsGoblin;
    char attackRandomize();
    std::string dialogue(); 
    void attack(char attackType, int &playerHealth);

private:
    
    std::vector<std::string> dialogueSentences = {"Goblins fight! Goblins strong!", "Big sword, small brain! Goblin smarter!", "Run away, big person! Goblin rule the day!"};
    
    std::vector<char> attackTypes = {'s', 'f', 'k'}; 
    
    std::vector<std::string> attackName = {"Goblin slash you with his knife!", "Goblin hits you with his fist!", "Goblin kicks you!"};

};
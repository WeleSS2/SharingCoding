#include "mobs.h"

char Dragon::attackRandomize() 
{
        int randomIndex = rand() % attackTypes.size();
        return attackTypes[randomIndex];
}
std::string Dragon::dialogue()
{
     int randomIndex = rand() % dialogueSentences.size();
     return dialogueSentences[randomIndex];
}

int Dragon::attack(char attackType)
{ 
    switch(attackType)
    {
        case 'f':
            std::cout << attackName[0] << std::endl;
            return 100;
        case 'b':
            std::cout << attackName[1] << std::endl;
            return 50;
        case 'c':
            std::cout << attackName[2] << std::endl;
            return 25;
    }
}

char Orc::attackRandomize() 
{
        int randomIndex = rand() % attackTypes.size();
        return attackTypes[randomIndex];
}

std::string Orc::dialogue()
{
     int randomIndex = rand() % dialogueSentences.size();
     return dialogueSentences[randomIndex];
}

int Orc::attack(char attackType, int &playerHealth)
{ 
    switch(attackType)
    {
        case 's':
            std::cout << attackName[0] << std::endl;
            playerHealth -= 20 * statsOrc.strength;
        case 'f':
            std::cout << attackName[1] << std::endl;
            playerHealth -= 5 * statsOrc.strength;
        case 'k':
            std::cout << attackName[2] << std::endl;
            playerHealth -= 10 * statsOrc.strength;
    }
}

char Goblin::attackRandomize() 
{
        int randomIndex = rand() % attackTypes.size();
        return attackTypes[randomIndex];
}

std::string Goblin::dialogue()
{
     int randomIndex = rand() % dialogueSentences.size();
     return dialogueSentences[randomIndex];
}

int Goblin::attack(char attackType, int &playerHealth)
{ 
    switch(attackType)
    {
        case 's':
            std::cout << attackName[0] << std::endl;
            playerHealth -= 10 * statsGoblin.strength;
        case 'f':
            std::cout << attackName[1] << std::endl;
            playerHealth -= 1 * statsGoblin.strength;
        case 'k':
            std::cout << attackName[2] << std::endl;
            playerHealth -= 5 * statsGoblin.strength;
    }
}
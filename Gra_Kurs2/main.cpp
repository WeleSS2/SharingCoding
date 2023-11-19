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

struct PlayerStats 
{   
    int hp =200;
    int strenght = 45;
    int defence = 55;
};

struct DragonStats 
{
    int hp = 800;
    int strength = 100; 
    int defence = 100;
    int level = 90;
};

struct GoblinStats
{
    int hp = 20;
    int strength = 5; 
    int defence = 1;
};

struct OrcStats
{
    int hp = 20;
    int strength = 5; 
    int defence = 1;
};

class Dragon 
{
private:
    std::vector<std::string> dialogue = {"Arghhh!", "I'm going to eat you!", "Your going to be my dinner!"};
    std::vector<char> attack = {'f', 'c', 't'}; 
    std::vector<std::string> attackName = {"Dragon throws fire at you!", "Dragon claws you!", "Dragon bites you!"};
    char attack()
        {
            int randomIndex = rand() % attack.size();
            return attack[randomIndex];
        }

public:
    std::string dialogue()
    {
        int randomIndex = rand() % dialogue.size();
        return dialogue[randomIndex];
    }    
    
    std::string attack()
    {
        switch(char)
        {
            case 'f':
                std::cout << attackName[0] << std::endl;
                break;
            case 'c':
                std::cout << attackName[1] << std::endl;
                break;
            case 't':
                std::cout << attackName[2] << std::endl;
                break;
        }
    }

private:
    std::string name = "Dragon";
    
    
    int damage(std::string attack)
    {
        if(attack == "f")
        {
            return 100;
        }
        else if(attack == "c")
        {
            return 50;
        }
        else if(attack == "t")
        {
            return 25;
        }
    }
};


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

class Locations
{
  public:

  void forest(){
    std::cout << "You enter a dark forest!";
    
  } 

  void dungeon(){
        std::cout << "You enter a dungeon!";
  } 
  
};



int main()
{
    srand(time(NULL));

    Player newPlayer;
    
    return 0;
}


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
//Typ | Nazwe     |  Liste parametrow (deklaracja),{definicja}
void   function      (); /// deklracja
void   function2     ()   { }; // definicja

void function ()
{

};



struct PlayerStats 
{   
    int hp =200;
    int strenght = 45;
    int defence = 55;
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

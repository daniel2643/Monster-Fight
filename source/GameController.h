//
//  GameController.h
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef GameController_h
#define GameController_h

#include <ctime>
#include <unistd.h>
//#include <windows.h>
#include <fstream>
#include "Character.h"
#include "Monster.h"
#include "Boss.h"
#include "Pet.h"
#include "Hero.h"
#include "UtilityFunctions.h"

using namespace std;

class GameController{
    
private:
    //Variables
    vector<Hero*> v_hero;
    vector<Pet*> v_pet;
    vector<Monster*> v_monster;
    int monster_index = 0;
    
    //Setup Functions
    void generateMonsters();
    void addHero();
    void addPet();
    
    //Play Functions
    void battle(Hero* hero, Pet* pet, Monster* monster);
    void attack(Hero* hero, Pet* pet, Monster* monster, bool* hero_special);
    void defend(Hero* hero, Monster* monster, bool* monster_special);
    void petDefend(Pet* pet, Monster* monster, bool* monster_special);
    
    //Display Functions
    void displayMenu();
    void displayHeroTypeSelection();
    void displayHeroInfo(Hero* hero);
    void displayPetInfo(Pet* pet);
    
    
public:
    GameController();
    
    void setup();
    void play();
    
    void saveGame();
    void loadGame();
    
    
    
};


#endif /* GameController_h */

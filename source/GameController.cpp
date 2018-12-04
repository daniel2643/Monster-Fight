//
//  GameController.cpp
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "GameController.h"

GameController::GameController(){
    setup();
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////SETUP FUNCTION////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameController::setup(){
    // Set non-seed random system
    srand(time(NULL));
    
    // Clear memory in Heap
    for (int i = 0; i< v_hero.size(); i++){
        delete v_hero[i];
        v_hero[i] = NULL;
        v_hero.erase(v_hero.begin() + i);
    }
    
    for (int i = 0; i< v_monster.size(); i++){
        delete v_monster[i];
        v_pet[i] = NULL;
        v_pet.erase(v_pet.begin() + i);
    }
    
    for (int i = 0; i< v_monster.size(); i++){
        delete v_monster[i];
        v_monster[i] = NULL;
        v_monster.erase(v_monster.begin() + i);
    }
    
    v_hero.clear();
    v_pet.clear();
    v_monster.clear();
    
    // Instantiate all characters
    ifstream infile;
    int c;
    infile.open("saves.txt");
    infile >> c;
    infile.close();
    
    if (getUserInputChar("Do you want to LOAD game? (Yes for 'y', No for other keys)") == 'y' && c != 0){
        loadGame();
    }
    else{
        addHero();
        addPet();
    }
    generateMonsters();
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////PLAY FUNCTION////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameController::play(){
    
    // Single Mode
    Hero* hero1 = v_hero[0];
    Pet* pet1 = v_pet[0];
    bool quit = false;
    
    
    while (monster_index < 5 && !quit){
        
        bool running = true;
        char command = ' ';
        
        while (running){
            displayMenu();
            command = getUserInputChar("Please choose an option");
            
            switch (command){
                case '1':
                    running = false;
                    break;
                case '2':
                    displayHeroInfo(hero1);
                    cout << "\n\n\n" << endl;
                    break;
                case '3':
                    displayPetInfo(pet1);
                    cout << "\n\n\n" << endl;
                    break;
                case 'q':
                    running = false;
                    quit = true;
                    if (getUserInputChar("Do you want to SAVE the game? (Yes for 'y', No for other keys)") == 'y'){
                        saveGame();
                    }
                        
                    break;
                default:
                    cout << "ERROR: Please re-enter a valid option" << endl;
            }
        }
        
        if (quit)
            break;
        
        cout << "\n\n\n\n" << endl;
        //////////////////////////////////////////////////////////////////////////////////////////////
        cout << "The battle " << monster_index+1 << " begins!"  << endl;
        usleep(1500000);
        //Sleep(1500);
        cout << hero1->getName() << "\t<--->\t" << v_monster[monster_index]->getName() << endl;
        battle(hero1, pet1, v_monster[monster_index]);
        if (hero1->getHealth() == 0){
            cout << "YOU LOSE" << "\n\n\n" << endl;
            break;
        }
        else{
            cout << "MONSTER" << " " << v_monster[monster_index]->getName() << " died~" << "\n\n\n" << endl;
            hero1->setMoney(hero1->getMoney() + hero1->getHealth());
            hero1->setHealth(hero1->getHealth() + 20);
            hero1->setAttack(hero1->getAttack() + rand() % 6);
            hero1->setDefence(hero1->getDefence() + rand() % 3);
            hero1->setSpecialAttack(hero1->getSpecialAttack() + rand() % 3);
            displayHeroInfo(hero1);
            if (monster_index==4){
                cout << hero1->toString() << endl;
                cout << "YOU WIN~~~~" << "\n\n\n" << endl;
            }
            
        }
        monster_index++;
    }
    
    
    // Clear memory
    delete hero1;
    hero1 = NULL;
    delete pet1;
    pet1 = NULL;
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////SETUP SUB FUNCTION////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GameController::generateMonsters(){
    
    Monster* monster1 = new Monster("Elder Fox", "Monster", 10, 1, 1);
    Monster* monster2 = new Monster("Dark Terror", "Monster", 20, 3, 2);
    Monster* monster3 = new Monster("Contaminated Batur Warrior", "Monster", 30, 5, 4);
    Monster* monster4 = new Monster("Bloody Lord", "Monster", 40, 6, 7);
    
    
    Monster* boss = new Boss("Antharas", "Boss", 50, 8, 8, 5);
    //    Boss* bossi = static_cast<Boss*>(boss);
    //    cout << bossi->getSpecialAttack() << endl;
    
    //    Boss* bossii = static_cast<Boss*>(monster4);
    //    cout << bossii->getSpecialAttack() << endl;
    
//    cout << boss->getCount() << endl;
//    cout << monster1->getCount() << endl;
    //
    v_monster.push_back(monster1);
    v_monster.push_back(monster2);
    v_monster.push_back(monster3);
    v_monster.push_back(monster4);
    v_monster.push_back(boss);
}

void GameController::addHero(){
    string user_sinput;
    char user_cinput;
    HeroType type;
    bool valid = false;
    Hero* hero;
    
    cout << "----- HERO CREATOR -----" << endl;
    user_sinput = getUserInput("Please enter your hero name");
    
    while(!valid){
        displayHeroTypeSelection();
        user_cinput = getUserInputChar("Please select the race type");
        
        switch (user_cinput){
            case '1':
                type = HUMAN;
                valid = true;
                hero = new Hero(user_sinput, type, 20, 3, 3, 2);
                break;
            case '2':
                type = ELF;
                valid = true;
                hero = new Hero(user_sinput, type, 18, 2, 2, 6);
                break;
            case '3':
                type = ORC;
                valid = true;
                hero = new Hero(user_sinput, type, 15, 5, 1, 3);
                break;
            case '4':
                type = DWARF;
                valid = true;
                hero = new Hero(user_sinput, type, 30, 2, 3, 1);
                break;
            case '5':
                type = KAMAEL;
                valid = true;
                hero = new Hero(user_sinput, type, 17, 4, 2, 7);
                break;
            default:
                cout << "ERROR: Please enter a valid class type" << endl;
        }
    }
    v_hero.push_back(hero);
    
    displayHeroInfo(hero);
    
}

void GameController::addPet(){
    string user_sinput;
    
    cout << "----- PET CREATOR -----" << endl;
    user_sinput = getUserInput("Please enter your pet name");
    
    
    Pet* pet = new Pet(user_sinput, "Pet", 30, 2, 2);
    v_pet.push_back(pet);
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////PLAY SUB FUNCTION////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameController::battle(Hero* hero, Pet* pet, Monster* monster){
    bool switcher = true;  //for change b/w attack and defend
    bool* hero_special = new bool(false);
    bool* monster_special = new bool(false);
    
    
    while (hero->getHealth() > 0 && monster->getHealth() > 0){
        if (switcher){
            cout << hero->getName() << " Attack " << monster->getName() << endl;
            usleep(100000);
            //Sleep(1500);
            attack(hero, pet, monster, hero_special);  //hero attack
            
        }
        else{
            if (monster->getType() == "Boss" && pet->getHealth() > 0 && pet->instantiateOrNot() &&rand() % 2 == 0){
                cout << monster->getName() << " Attack "<< pet->getName() << endl;
                usleep(100000);
                //Sleep(1500);
                petDefend(pet, monster, monster_special);  //pet defend
                cout << pet->toString() << endl;
                if (pet->getHealth() == 0){
                    cout << pet->getName() << " died~~~~~~~~" << endl;
                }
                
            }
            else{
                cout << monster->getName() << " Attack "<< hero->getName() << endl;
                usleep(100000);
                //Sleep(1500);
                defend(hero, monster, monster_special);  //hero defend
            }
            
            
        }
        usleep(100000);
        //Sleep(1500);
        cout << hero->toString() << "\n" << monster->toString() << "\n\n\n\n" << endl;
        switcher = !switcher;
    }
    
    delete hero_special;
    hero_special = NULL;
    delete monster_special;
    monster_special = NULL;
    
}


void GameController::attack(Hero* hero, Pet* pet, Monster* monster, bool* hero_special){
    int hero_attack = rand() % 6 + 1;
    int pet_attack;
    int monster_defence = rand() % 6 + 1;
    char user_command = 'n';
    
    hero_attack += hero->getAttack();
    monster_defence += monster->getDefence();
    
    if (!*hero_special){
        user_command = getUserInputChar("Do you want to use Special Attack?(Yes for 'y' , No for any keys)");
        
        if (user_command == 'y'){
            hero_attack += hero->getSpecialAttack();
            *hero_special = true;
        }
    }
    
    
    
    cout << hero_attack << "   " << monster_defence << endl;
    if (hero_attack > monster_defence){
        cout << hero->getName() << " deals " << (hero_attack - monster_defence) << " damage to " << monster->getName() << endl;
        cout << (monster->getHealth()-hero_attack+monster_defence) << endl;
        monster->setHealth(monster->getHealth()-hero_attack+monster_defence);
    }
    else {
        cout << monster->getName() << " succeeded in defending "<< hero->getName() <<"'s attack" << "\n\n";
    }
    
    // Pet attack monster
    if (monster->getType() == "Boss" && pet->getHealth() > 0){
        if (!pet->instantiateOrNot()){
            cout << "Do you want to call your pet?(Yes for 'y' , No for any keys) " << endl;
            cin >> user_command;
        }
        if (user_command == 'y' or pet->instantiateOrNot()){
            pet->setInstantiation(true);
            if (rand() % 7 >= 0){
                pet_attack = 0;
            }
            else{
                pet_attack = rand() % 3 + 1;
                pet_attack += pet->getAttack();
            }
            if (pet_attack > 0){
                cout << pet->getName() << " deals " << pet_attack << " damage to " << monster->getName() << endl;
            }
            else{
                cout << monster->getName() << " succeeded in avoiding "<< pet->getName() <<"'s attack" << "\n\n";
            }
        }
    }
}


void GameController::defend(Hero* hero, Monster* monster, bool* monster_special){
    int monster_attack = rand() % 6 + 1;
    int hero_defence = rand() % 6 + 1;
    
    monster_attack += monster->getAttack();
    hero_defence += hero->getDefence();
    
    
    
    if (!*monster_special && monster->getType() == "Boss"){
        if (rand() % 7 > 0){
            cout << monster->getName() << " uses the special attack!" << endl;
            Boss* bossy = static_cast<Boss*>(monster);
            cout << bossy->getCount() << endl;
            monster_attack += bossy->getSpecialAttack();
            *monster_special = true;
        }
    }
    
    
    cout << monster_attack << "   " << hero_defence << endl;
    if (monster_attack > hero_defence){
        cout << monster->getName() << " deals " << (monster_attack - hero_defence) << " damage to " << hero->getName() << endl;
        cout << (hero->getHealth()-monster_attack+hero_defence) << endl;
        hero->setHealth(hero->getHealth()-monster_attack+hero_defence);
    }
    else {
        cout << hero->getName() << " succeeded in defending "<< monster->getName() <<"'s attack" << "\n\n";
    }
}

void GameController::petDefend(Pet* pet, Monster* monster, bool* monster_special){
    int monster_attack = rand() % 6 + 1;
    int pet_defence = rand() % 3 + 1;
    
    monster_attack += monster->getAttack();
    pet_defence += pet->getDefence();
    
    
    if (!*monster_special && monster->getType() == "Boss"){
        if (rand() % 7 > 4){
            cout << monster->getName() << " uses the special attack!" << endl;
            Boss* bossy = static_cast<Boss*>(monster);
            cout << bossy->getCount() << endl;
            monster_attack += bossy->getSpecialAttack();
            *monster_special = true;
        }
    }
    
    cout << monster_attack << "   " << pet_defence << endl;
    if (monster_attack > pet_defence){
        cout << monster->getName() << " deals " << (monster_attack - pet_defence) << " damage to " << pet->getName() << endl;
        cout << (pet->getHealth()-monster_attack+pet_defence) << endl;
        pet->setHealth(pet->getHealth()-monster_attack+pet_defence);
    }
    else {
        cout << pet->getName() << " succeeded in defending "<< monster->getName() <<"'s attack" << "\n\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////DISPLAY FUNCTION////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameController::displayMenu(){
    cout << "----- MENU -----" << endl;
    cout << "1: Start Battle" << endl;
    cout << "2: View Hero Information" <<endl;
    cout << "3: View Pet Information" << endl;
    cout << "q: Quit Application" <<endl;
    cout << "----------------" << endl;
}

    
void GameController::displayHeroTypeSelection(){
    cout << "----- RACE -----"<< endl;
    cout << "1: Human" << endl;
    cout << "2: Elf" << endl;
    cout << "3: Orc" << endl;
    cout << "4. Dwarf" << endl;
    cout << "5. Kamael" << endl;
    cout << "-----------------" << endl;
}

void GameController::displayHeroInfo(Hero* hero){
    cout << hero->toString() << endl;
}

void GameController::displayPetInfo(Pet* pet){
    cout << pet->toString() << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////SAVE && LOAD//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameController::saveGame(){
    ofstream outfile;
    outfile.open("saves.txt");
    for (int i = 0; i < v_hero.size(); i++){
        outfile << v_hero[i]->getName().length() <<"\t"<< v_hero[i]->getName() << "\t" << v_hero[i]->getEType() << "\t" << v_hero[i]->getHealth() << "\t" << v_hero[i]->getAttack() << "\t" << v_hero[i]->getDefence() << "\t" << v_hero[i]->getSpecialAttack() << "\t" << v_hero[i]->getMoney() << endl;
    }
    outfile << "\n";
    
    for (int i = 0; i < v_pet.size(); i++){
        outfile << v_pet[i]->getName().length()<< "\t" <<  v_pet[i]->getName() << "\t" << v_pet[i]->getType().size() << "\t" << v_pet[i]->getType() << "\t" << v_pet[i]->getHealth() << "\t" << v_pet[i]->getAttack() << "\t" << v_pet[i]->getDefence() << endl;
    }
    outfile << "\n";
    
    outfile << monster_index;
    
    outfile.close();
    
}




void GameController::loadGame(){
    int hero_name_size;
    string hero_name = "";
    int hero_type;
    int hero_health;
    int hero_attack;
    int hero_defence;
    int hero_special_attack;
    int hero_money;
    
    int pet_name_size;
    string pet_name = "";
    int pet_type_size;
    string pet_type = "";
    int pet_health;
    int pet_attack;
    int pet_defence;
    
    char tmp;
    
    ifstream infile;
    infile.open("saves.txt");
    
    // load hero data
    infile >> hero_name_size;
    for (int i = 0; i < hero_name_size; i++){
        infile >> tmp;
        hero_name += tmp;
    }
    infile >> hero_type >> hero_health >> hero_attack >> hero_defence >> hero_special_attack >> hero_money;
    HeroType e_type;
    switch(hero_type)
    {
        case 1:
             e_type = HUMAN;
            break;
        case 2:
             e_type = ELF;
            break;
        case 3:
             e_type = ORC;
            break;
        case 4:
             e_type = DWARF;
            break;
        case 5:
             e_type = KAMAEL;
            break;
        default:
             e_type = NONE;
            
    }
    v_hero.push_back(new Hero(hero_name, e_type, hero_health, hero_attack, hero_defence, hero_special_attack, hero_money));
    
    // load pet data
    infile >> pet_name_size;
    for (int i = 0; i < pet_name_size; i++){
        infile >> tmp;
        pet_name += tmp;
    }
    infile >> pet_type_size;
    for (int i = 0; i < pet_type_size; i++){
        infile >> tmp;
        pet_type += tmp;
    }
    
    infile >> pet_health >> pet_attack >> pet_defence;
    v_pet.push_back(new Pet(pet_name, pet_type, pet_health, pet_attack, pet_defence));
    
    
    
    // load monster index
    infile >> monster_index;
    
    infile.close();

    
}

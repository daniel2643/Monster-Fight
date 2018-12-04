//
//  Hero.cpp
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Hero.h"

int Hero::hero_count = 0;

// Constructors and Destructor using inheritance
Hero::Hero() : Character(){
    
    type = NONE;
    special_attack = 0;
    money = 0;
    setMax();
    hero_count++;
}

Hero::Hero(string init_name, HeroType init_type, int init_health, int init_attack, int init_defence, int init_special_attack) : Character(init_name, init_health, init_attack, init_defence){
    type = init_type;
    special_attack = init_special_attack;
    money = 0;
    setMax();
    hero_count++;
}

Hero::Hero(string init_name, HeroType init_type, int init_health, int init_attack,  int init_defence, int init_special_attack, int init_money) : Character(init_name, init_health, init_attack, init_defence){
    type = init_type;
    special_attack = init_special_attack;
    money = init_money;
    setMax();
    hero_count++;
}

Hero::~Hero(){
    hero_count--;
}

// Extra Accessors
string Hero::getType(){
    switch(type)
    {
        case HUMAN:
            return "Hero(Human)";
        case ELF:
            return "Hero(Elf)";
        case ORC:
            return "Hero(Orcish)";
        case DWARF:
            return "Hero(Dwarf)";
        case KAMAEL:
            return "Hero(Kamael)";
        case NONE:
            return "None?";
    }
}

HeroType Hero::getEType(){
    return type;
}

int Hero::getSpecialAttack(){
    return special_attack;
}

int Hero::getMoney(){
    return money;
}

int Hero::getCount(){
    return hero_count;
}

// Extra Mutators
void Hero::setMax(){
    switch(type)
    {
        case HUMAN:
            max_health = 50;
            max_attack = 10;
            max_defence = 10;
            max_special_attack = 10;
            break;
        case ELF:
            max_health = 48;
            max_attack = 9;
            max_defence = 9;
            max_special_attack = 15;
            break;
        case ORC:
            max_health = 45;
            max_attack = 15;
            max_defence = 9;
            max_special_attack = 9;
            break;
        case DWARF:
            max_health = 65;
            max_attack = 9;
            max_defence = 10;
            max_special_attack = 7;
            break;
        case KAMAEL:
            max_health = 52;
            max_attack = 12;
            max_defence = 8;
            max_special_attack = 18;
            break;
        case NONE:
            max_health = 50;
            max_attack = 10;
            max_defence = 10;
            max_special_attack = 10;
            break;
        default:
            max_health = 50;
            max_attack = 10;
            max_defence = 10;
            max_special_attack = 10;
    }
}


void Hero::setHealth(int new_health){
    
    if (new_health < 0 ){
        new_health = 0;
        *health = new_health;
    }
    else if (new_health <= max_health){
        *health = new_health;
    }
    else if (new_health > max_health){
        *health = max_health;
    }
}

void Hero::setAttack(int new_attack){
    
    if (new_attack <= max_attack and new_attack > attack){
        attack = new_attack;
    }
    else if (new_attack > max_attack){
        attack = max_attack;
    }
}
void Hero::setDefence(int new_defence){
    
    if (new_defence <= max_defence and new_defence > defence){
        defence = new_defence;
    }
    else if (new_defence > max_defence){
        defence = max_defence;
    }
    
}
void Hero::setSpecialAttack(int new_special_attack){
    if (new_special_attack <= max_special_attack and new_special_attack > special_attack){
        special_attack = new_special_attack;
    }
    else if (new_special_attack > max_special_attack ){
        special_attack = max_special_attack;
    }
    
}

void Hero::setMoney(int new_money){
    if (new_money > 0){
        money = new_money;
    }
}



// toString method
string Hero::toString(){
    stringstream ss;
    
    ss << "Name: " << name << "\t\tType: " << Hero::getType() << "\n\tHP: " << *health << "/" << max_health << " \tATT: "
    << attack << "\tDEF: " << defence << "\tSpecial ATT: " << special_attack << "\n\tMoney: " << money << endl;
    
    return ss.str();
}

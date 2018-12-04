//
//  Character.cpp
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Character.h"

int Character::character_count = 0;

// Constructors and Destructor
Character::Character(){
    name = "Undefined";
    attack = 0;
    health = 0;
    max_health = 0;
    character_count++;
}

Character::Character(string init_name, int init_health, int init_attack, int init_defence){
    name = init_name;
    health = new int(init_health);
    max_health = init_health;
    attack = init_attack;
    defence = init_defence;
    character_count++;
}

Character::~Character(){
    delete health;
    health = NULL;
    character_count--;
}

// Accessors
int Character::getHealth(){
    return *health;
}

int Character::getAttack(){
    return attack;
}

int Character::getDefence(){
    return defence;
}

int Character::getCount(){
    return character_count;
}

// Mutators
void Character::setName(string new_name){
    if (new_name != ""){
        name = new_name;
    }
    
}

void Character::setHealth(int new_health){
    if (new_health < 0 ){
        new_health = 0;
        *health = new_health;
    }
    else if (new_health <= max_health){
        *health = new_health;
    }
}



// toString method
string Character::toString(){
    stringstream ss;
    
    ss << "Name: " << name << "\t\tType: " << "None?" << "\n\tHP: " << *health << "/" << max_health << " \tATT: "
    << attack << "\tDEF: " << defence << endl;
    
    return ss.str();
}

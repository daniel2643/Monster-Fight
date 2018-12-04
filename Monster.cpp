//
//  Monster.cpp
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Monster.h"

int Monster::monster_count = 0;

// Constructor and Destructor using inheritance
Monster::Monster() : Character(){
    monster_count++;
}

Monster::Monster(string init_name, string init_type, int init_health, int init_attack, int init_defence) : Character(init_name, init_health, init_attack, init_defence){
    monster_count++;
    
}

Monster::~Monster(){
    monster_count--;
}

// Extra Accessors


int Monster::getCount(){
    return monster_count;
}

string Monster::getType(){
    return type;
}

// Extra Mutators



// toString method
string Monster::toString(){
    stringstream ss;
    
    ss << "Name: " << name << "\n\tHP: " << *health << "/" << max_health << " \tATT:" << attack << "\tDEF: " << defence << endl;
    
    return ss.str();
}

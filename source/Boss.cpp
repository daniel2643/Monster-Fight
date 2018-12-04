//
//  Boss.cpp
//
//  Created by Daniel on 13/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Boss.h"

int Boss::boss_count = 0;

//Constructors and Destructor using inheritance
Boss::Boss() : Monster(){
    special_attack = 0;
    boss_count++;
}

Boss::Boss(string init_name, string init_type, int init_health, int init_attack, int init_defence, int init_special_attack) : Monster(init_name, init_type, init_health, init_attack, init_defence){
    special_attack = init_special_attack;
    boss_count++;
}

Boss::~Boss(){
    boss_count--;
}

// Extra Accessors
int Boss::getSpecialAttack(){
    return special_attack;
}

int Boss::getCount(){
    return boss_count;
}


// Extra Mutators





// toString method using inheritance
string Boss::toString(){
    stringstream ss;
    
    ss << Monster::toString() << "\tSpecial ATT: " << special_attack << endl;
    
    return ss.str();
}

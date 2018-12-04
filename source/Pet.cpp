//
//  Pet.cpp
//
//  Created by Daniel on 16/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Pet.h"

int Pet::pet_count = 0;

// Constructor and Destructor using inheritance
Pet::Pet() : Monster(){
    pet_count++;
}

Pet::Pet(string init_name, string init_type, int init_health, int init_attack, int init_defence) : Monster(init_name, init_type, init_health, init_attack, init_defence){
    pet_count++;
    
}

Pet::~Pet(){
    pet_count--;
}

// Extra Accessors
int Pet::getCount(){
    return pet_count;
}

bool Pet::instantiateOrNot(){
    return instantiation;
}

// Extra Mutators
void Pet::setInstantiation(bool new_instantiation){
    instantiation = new_instantiation;
}



// toString method using inheritance
string Pet::toString(){
    stringstream ss;
    
    ss << Monster::toString();
    
    return ss.str();
}

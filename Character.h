//
//  Character.h
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Character{
    
protected:
    string name;
    string type;
    int* health;
    int max_health;
    int attack;
    int defence;
    static int character_count;
    
    
public:
    Character();
    Character(string init_name, int init_health, int init_attack, int init_defence);
    virtual ~Character();
    
    //Accessors
    string getName() {return name;}
    int getHealth();
    int getAttack();
    int getDefence();
    virtual int getCount();
    
    //Mutators
    void setName(string new_name);
    void setHealth(int new_health);
    
    
    
    //toString method
    virtual string toString() = 0;   //virtual means allow polymorphism( Character a = Fighter()
    
    
};

#endif /* Character_h */

//
//  Hero.h
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Hero_h
#define Hero_h

#include "Character.h"

enum HeroType
{
    NONE,
    HUMAN,
    ELF,
    ORC,
    DWARF,
    KAMAEL
};

class Hero : public Character{
    
protected:
    HeroType type;
    int special_attack;
    int money;
    static int hero_count;
    
    int max_health;
    int max_attack;
    int max_defence;
    int max_special_attack;
    
    void setMax();
    
public:
    // Constructor and Destructor
    Hero();
    Hero(string init_name, HeroType init_type, int init_health, int init_attack, int init_defence, int init_special_attack);
    Hero(string init_name, HeroType init_type, int init_health, int init_attack, int init_defence, int init_special_attack, int init_money);
    virtual ~Hero();
    
    // Accessors
    string getType();
    HeroType getEType();
    int getSpecialAttack();
    int getMoney();
    virtual int getCount();
    
    // Mutators
    void setHealth(int new_health);
    void setAttack(int new_attack);
    void setDefence(int new_defence);
    void setSpecialAttack(int new_special_attack);
    void setMoney(int new_money);
    
    // toString Method
    virtual string toString();
    
    
    
};


#endif /* Hero_h */

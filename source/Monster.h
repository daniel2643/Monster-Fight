//
//  Monster.h
//
//  Created by Daniel on 06/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Monster_h
#define Monster_h

#include "Character.h"

class Monster : public Character{
    
protected:
    string type;
    static int monster_count;
    
public:
    Monster();
    Monster(string init_name, string init_type, int init_health, int init_attack, int init_defence);
    virtual ~Monster();
    
    string getType();
    virtual int getCount();
    virtual string toString();
    
    
};

#endif /* Monster_h */

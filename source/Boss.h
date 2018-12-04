//
//  Boss.h
//
//  Created by Daniel on 13/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Boss_h
#define Boss_h

#include "Monster.h"


class Boss : public Monster{
    
protected:
    int special_attack = 0;
    static int boss_count;
    
public:
    Boss();
    Boss(string init_name, string init_type, int init_health, int init_attack, int init_defence, int init_special_attack);
    ~Boss();
    
    int getSpecialAttack();
    virtual int getCount();
    virtual string toString();
    
};


#endif /* Boss_h */

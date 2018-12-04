//
//  Pet.h
//
//  Created by Daniel on 16/10/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Pet_h
#define Pet_h



#include "Monster.h"

class Pet : public Monster{
    
protected:
    
    bool instantiation = false;
    static int pet_count;
    
public:
    Pet();
    Pet(string init_name, string init_type, int init_health, int init_attack, int init_defence);
    virtual ~Pet();
    
    virtual int getCount();
    virtual string toString();
    virtual bool instantiateOrNot();
    
    void setInstantiation(bool new_instantiation);
};

#endif /* Pet_h */


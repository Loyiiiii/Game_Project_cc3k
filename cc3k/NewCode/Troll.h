#ifndef TROLL_H
#define TROLL_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Troll : public PlayerCharacter {
public:
    Troll();
    void gainHP();
};

#endif 
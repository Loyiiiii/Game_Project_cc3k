#ifndef TROLL_H
#define TROLL_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

// troll (120 HP, 25 Atk, 15 Def, regains 5 HP every turn; HP is capped at 120 HP)
class Troll : public PlayerCharacter {
    public:
        Troll();
        void gainHP(); // regains 5 HP every turn; -> add in GamePlay
};

#endif 

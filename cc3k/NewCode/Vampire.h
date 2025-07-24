#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

// vampire: 50 HP, 25 ATK, 25 Def.
// no Max HP, and gains 5HP per successful attack. 
class Vampire : public PlayerCharacter {
    public:
        void gainHP(); // gain 5HP per successful attack. 
        Vampire();
        std::string attack(Enemy& enemy) override;
};

#endif 

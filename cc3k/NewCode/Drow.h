#ifndef DROW_H
#define DROW_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Drow : public PlayerCharacter {
    float potion_effect_enhancement = 1.5;
public:
    Drow();
    void drinkPotion(Potion& p) override;
};

#endif 
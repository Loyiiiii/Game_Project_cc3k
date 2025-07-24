#ifndef DROW_H
#define DROW_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

// Drow: 150 HP, 25 Atk, 15 Def
class Drow : public PlayerCharacter {
    private:
        // potion effect enhancement
        float potion_effect_enhancement = 1.5;

    public:
        Drow();
        // override by magnifying the potion effect *1.5.
        void drinkPotion(Potion& p) override;
};

#endif 

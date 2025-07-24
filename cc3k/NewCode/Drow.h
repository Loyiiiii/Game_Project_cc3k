#ifndef DROW_H
#define DROW_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Drow : public PlayerCharacter {
    private:
        // potion effect enhancement
        float potion_effect_enhancement = 1.5;

    public: // constructor
        Drow();
        void drinkPotion(Potion& p) override;
};

#endif 

export module Drow;

import PlayerCharacter;
import Global_Constants;

export class Drow: public PlayerCharacter {
    // drow: 150 HP, 25 ATK, 15 Def.
    // Ability: all potions have effect magnified by 1.5x
    float potion_effect_enhancement = 1.5;
    public: 
        Drow();
        // need to override - all potions have effect magnified by 1.5x
        void drinkPotion(Potion& p) override;
};

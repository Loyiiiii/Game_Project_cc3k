import PlayerCharacter;
import Global_Constants;

export module Drow;

export class Drow: public PlayerCharacter {
    // drow: 150 HP, 25 ATK, 15 Def.
    // Ability: all potions have effect magnified by 1.5x
    public: 
        Drow(Position pos);
        // need to override - all potions have effect magnified by 1.5x
        void drinkPotion(Potion p) override; 
};

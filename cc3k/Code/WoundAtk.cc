export module wound_atk;

import potion;
import Global_Constants;

export class WoundAtk : public Potion {
public:
    WoundAtk(); // Constructor for WoundAtk potion
    // Inherits from Potion, which has the type WOUND_ATK, is temporary,
    // has an amount of -5, and a symbol 'P'.
    // The symbol 'P' is used to represent the potion in the game.
    // The WoundAtk potion temporarily decreases the player's attack by 5.
};

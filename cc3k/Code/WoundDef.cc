export module wound_def;

import potion;

export class WoundDef : public Potion {
public:
    WoundDef(); // Constructor for WoundDef potion
    // Inherits from Potion, which has the type WOUND_DEF, is temporary,
    // has an amount of -5, and a symbol 'P'.
    // The symbol 'P' is used to represent the potion in the game.
    // The WoundDef potion temporarily decreases the player's defense by 5.
}

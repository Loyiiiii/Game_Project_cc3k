export module poison_health;

import potion;

export class PoisonHealth : public Potion {
public:
    PoisonHealth(); // Constructor for PoisonHealth potion
    // Inherits from Potion, which has the type POISON_HEALTH, is temporary,
    // has an amount of -10, and a symbol 'P'.
    // The symbol 'P' is used to represent the potion in the game.
    // The PoisonHealth potion permanently decreases the player's health by 10.
};

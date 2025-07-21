export module restore_health;

import potion;

export class RestoreHealth : public Potion {
public:
    RestoreHealth(); // Constructor for RestoreHealth potion
    // Inherits from Potion, which has the type HEALTH_RESTORE, is not temporary,
    // has an amount of 10, and a symbol 'P'.
    // The symbol 'P' is used to represent the potion in the game.
}

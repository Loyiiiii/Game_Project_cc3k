export module boost_def;

import potion;

export class BoostDef : public Potion {
public:
    BoostDef(); // Constructor for BoostDef potion
    // Inherits from Potion, which has the type DEF_BOOST, is temporary,
    // has an amount of 5, and a symbol 'P'.
    // The symbol 'D' is used to represent the potion in the game.
    // The BoostDef potion temporarily increases the player's defense power by 5.
    // It is used to boost the player's defense in combat situations.
    // The potion is temporary, meaning its effects will wear off after getting to a new floor
};

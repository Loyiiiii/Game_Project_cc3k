export module boost_atk;

import potion;

export class BoostAtk : public Potion {
public:
    BoostAtk(); // Constructor for BoostAtk potion
    // Inherits from Potion, which has the type ATK_BOOST, is temporary,
    // has an amount of 5, and a symbol 'P'.
    // The symbol 'P' is used to represent the potion in the game.
    // The BoostAtk potion temporarily increases the player's attack power by 5.
    // It is used to boost the player's attack in combat situations.
    // The potion is temporary, meaning its effects will wear off after a certain period or condition
};

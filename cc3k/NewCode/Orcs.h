#ifndef ORCS_H
#define ORCS_H

#include "Enemy.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"

// Orcs: 180 HP, 30 Atk, 25 Def
// 50% more damage to Goblins.
class Orcs : public Enemy {
public:
    Orcs(Position pos);
    std::string attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 

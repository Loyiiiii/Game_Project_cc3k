#ifndef ORCS_H
#define ORCS_H

#include "Enemy.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Orcs : public Enemy {
public:
    Orcs(Position pos);
    void attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 
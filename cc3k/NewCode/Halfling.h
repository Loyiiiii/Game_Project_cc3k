#ifndef HALFLING_H
#define HALFLING_H

#include "Enemy.h"
#include "Position.h"
#include "Global_Constants.h"

class Halfling : public Enemy {
public:
    Halfling(Position pos);
    void attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 
#ifndef HALFLING_H
#define HALFLING_H

#include "Enemy.h"
#include "Position.h"
#include "Global_Constants.h"

// Halfling: 100 HP, 15 Atk, 20 Def
// 50% chance for PC to miss. 

class Halfling : public Enemy {
public:
    Halfling(Position pos);
    std::string attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 

#ifndef DWARF_H
#define DWARF_H

#include "Enemy.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Dwarf : public Enemy {
public:
    Dwarf(Position pos);
    ~Dwarf();
    std::string attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 

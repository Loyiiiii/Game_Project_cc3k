#ifndef ELF_H
#define ELF_H

#include "Enemy.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Elf : public Enemy {
    public:
        Elf(Position pos);
        std::string attack(PlayerCharacter& pc) override;
        void dropGold(PlayerCharacter& pc) override;
        void takeDamage(int damage) override;
};

#endif 

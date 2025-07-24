#ifndef GOBLIN_H
#define GOBLIN_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

// Goblin: 110 HP, 15 Atk, 20 Def, steals 5 gold from every enemy slain.
class Goblin : public PlayerCharacter {
    private:
        void StealGold();
    public:
        Goblin();
        std::string attack(Enemy& e) override;
};

#endif 

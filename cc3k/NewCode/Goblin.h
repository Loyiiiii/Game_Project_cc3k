#ifndef GOBLIN_H
#define GOBLIN_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Goblin : public PlayerCharacter {
private:
    void StealGold();
public:
    Goblin();
    void attack(Enemy& e) override;
};

#endif 
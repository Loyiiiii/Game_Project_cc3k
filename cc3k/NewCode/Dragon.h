#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
#include "PlayerCharacter.h"
#include "DragonHoard.h"
#include "Global_Constants.h"
#include <memory>

class Dragon : public Enemy {
    std::unique_ptr<DragonHoard> drag_hoard;
public:
    Dragon(Position pos, std::unique_ptr<DragonHoard> hoard);
    ~Dragon();
    std::string attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int dmg) override;
};

#endif 
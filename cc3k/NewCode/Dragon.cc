#include "Dragon.h"
#include "PlayerCharacter.h"
#include "DragonHoard.h"
#include "Global_Constants.h"
#include <string>

Dragon::Dragon(Position pos, DragonHoard *hoard) :
    Enemy{ pos, 150, 20, 20, false, true, 'D' }, drag_hoard{hoard} {
    drag_hoard->setIsPickable(false);
}

Dragon::~Dragon() {}

std::string Dragon::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->getAtk(), pc.getDef());
    pc.takeDamage(damage);
    std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
    return msg;
}

void Dragon::dropGold(PlayerCharacter& pc) {
    drag_hoard->setIsPickable(true);
}

void Dragon::takeDamage(int dmg) {
    if (this->getHP() - dmg <= 0) {
        setHP(0);
    }
    else {
        setHP(this->getHP() - dmg);
    }
} 

DragonHoard* Dragon::getHoard() const { return drag_hoard; }

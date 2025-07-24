#include "Dragon.h"
#include "PlayerCharacter.h"
#include "DragonHoard.h"
#include "Global_Constants.h"

Dragon::Dragon(Position pos, std::unique_ptr<DragonHoard> hoard) :
    Enemy{ pos, 150, 20, 20, false, true, 'D' }, drag_hoard{ std::move(hoard) } {
    drag_hoard->setIsPickable(false);
}

Dragon::~Dragon() {}

void Dragon::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->getAtk(), pc.getDef());
    pc.takeDamage(damage);
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
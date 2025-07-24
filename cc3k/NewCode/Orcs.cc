#include "Orcs.h"
#include <cstdlib>

Orcs::Orcs(Position pos) :
    Enemy{ pos, 180, 30, 25, true, true, 'O' } {}

void Orcs::attack(PlayerCharacter& pc) {
    int normal_damage = calculateDamage(getAtk(), pc.getDef());
    if (pc.getRace() == Race::GOBLIN) {
        int augmented_dmg = normal_damage * 1.5;
        pc.takeDamage(augmented_dmg);
    }
    else {
        pc.takeDamage(normal_damage);
    }
}

void Orcs::dropGold(PlayerCharacter& pc) {
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2;
    pc.addGold(value);
}

void Orcs::takeDamage(int dmg) {
    if (getHP() - dmg <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - dmg);
    }
} 
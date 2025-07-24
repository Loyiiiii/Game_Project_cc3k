#include "Dwarf.h"
#include "PlayerCharacter.h"
#include <cstdlib>

Dwarf::Dwarf(Position pos) :
    Enemy{ pos, 100, 20, 30, true, true, 'W' } {}

void Dwarf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
}

void Dwarf::dropGold(PlayerCharacter& pc) {
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2;
    pc.addGold(value);
}

void Dwarf::takeDamage(int damage) {
    if (getHP() - damage <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - damage);
    }
} 
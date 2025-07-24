#include "Elf.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"
#include <cstdlib>

Elf::Elf(Position pos) :
    Enemy{ pos, 140, 30, 10, true, true, 'E' } {}

void Elf::attack(PlayerCharacter& pc) {
    if (pc.getRace() == Race::DROW) {
        int damage = calculateDamage(getAtk(), pc.getDef());
        pc.takeDamage(damage);
    }
    else {
        for (int i = 0; i < 2; i++) {
            int damage = calculateDamage(getAtk(), pc.getDef());
            pc.takeDamage(damage);
        }
    }
}

void Elf::dropGold(PlayerCharacter& pc) {
    int randomNum_gold = rand() % 2;
    int value = (randomNum_gold == 0) ? 1 : 2;
    pc.addGold(value);
}

void Elf::takeDamage(int damage) {
    if (getHP() - damage <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - damage);
    }
} 
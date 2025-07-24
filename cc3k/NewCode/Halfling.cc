#include "Halfling.h"
#include "PlayerCharacter.h"
#include <cstdlib>
#include <iostream>

Halfling::Halfling(Position pos) : Enemy{ pos, 100, 15, 20, true, true, 'L' } {}

void Halfling::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
}

void Halfling::dropGold(PlayerCharacter& pc) {
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2;
    pc.addGold(value);
}

void Halfling::takeDamage(int damage) {
    if (rand() % 2 == 0) {
        std::cout << "Halfling evaded the attack." << std::endl;
        return;
    }
    if (getHP() - damage <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - damage);
    }
} 
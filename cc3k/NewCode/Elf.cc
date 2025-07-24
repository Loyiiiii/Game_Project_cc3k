#include "Elf.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"
#include <cstdlib>
#include <string>

Elf::Elf(Position pos) :
    Enemy{ pos, 140, 30, 10, true, true, 'E' } {}

std::string Elf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    // checking if the PC is Drow 
    if (pc.getRace() == Race::DROW) {
        // int damage = calculateDamage(getAtk(), pc.getDef());
        pc.takeDamage(damage); // only get one attack
        std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
        return msg;
    }
    else {
        for (int i = 0; i < 2; i++) {
            pc.takeDamage(damage); // get 2 attacks.
        }
        std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(2 * damage) + " damage to PC. ";
        return msg;
    }
}

void Elf::dropGold(PlayerCharacter& pc) {
    int randomNum_gold = rand() % 2;
    int value = (randomNum_gold == 0) ? 1 : 2; // 1 for small gold, 2 for normal gold
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

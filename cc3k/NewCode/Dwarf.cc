#include "Dwarf.h"
#include "PlayerCharacter.h"
#include <cstdlib>
#include <string>

Dwarf::Dwarf(Position pos) :
    Enemy{pos, 100, 20, 30, true, true, 'W'} {}

Dwarf::~Dwarf() {}

std::string Dwarf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
    std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
    return msg;
}

void Dwarf::dropGold(PlayerCharacter& pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2; // 1 for small gold, 2 for normal gold
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

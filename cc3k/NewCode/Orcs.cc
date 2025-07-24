#include "Orcs.h"
#include <cstdlib>
#include <string>

Orcs::Orcs(Position pos) :
    Enemy{ pos, 180, 30, 25, true, true, 'O' } {}

std::string Orcs::attack(PlayerCharacter& pc) {
    int normal_damage = calculateDamage(getAtk(), pc.getDef());
    // checking if the PC is Goblins
    if (pc.getRace() == Race::GOBLIN) {
        int augmented_dmg = normal_damage * 1.5; // 50% more damage to Goblins.
        pc.takeDamage(augmented_dmg); 
        std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(augmented_dmg) + " damage to PC. ";
        return msg;
    }
    else {
        pc.takeDamage(normal_damage); // else just normal damage.
        std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(normal_damage) + " damage to PC. ";
        return msg;
    }
}

void Orcs::dropGold(PlayerCharacter& pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2;
    pc.addGold(value);
}

void Orcs::takeDamage(int dmg) {
    if (getHP() - dmg <= 0) {
        setHP(0); // dead.
    }
    else {
        setHP(getHP() - dmg);
    }
} 

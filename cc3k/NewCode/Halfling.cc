#include "Halfling.h"
#include "PlayerCharacter.h"
#include <cstdlib>
#include <iostream>


Halfling::Halfling(Position pos) : 
    Enemy{ pos, 100, 15, 20, true, true, 'L' } {}

std::string Halfling::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
    std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
    return msg;
}

void Halfling::dropGold(PlayerCharacter& pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2;
    int value = (randomNum == 0) ? 1 : 2;
    pc.addGold(value);
}

void Halfling::takeDamage(int damage) {
    // 50% chance for PC to miss. 
    if (rand() % 2 == 0) {
        // PC misses.
        std::cout << "Halfling has dodged the attack." << std::endl; // print to notify the player.
        return;
    }
    if (getHP() - damage <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - damage);
    }
} 

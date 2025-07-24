#include "Human.h"
#include "PlayerCharacter.h"
#include "NormalGold.h"
#include <string>

// Human: 140HP, 20Atk, 20Def, - drops 2 normal piles when dead
Human::Human(Position pos) :
    Enemy{ pos, 140, 20, 20, true, true, 'H' } {
    gold_carried.emplace_back(std::make_unique<NormalGold>());
    gold_carried.emplace_back(std::make_unique<NormalGold>());
}

Human::~Human() {}

std::string Human::attack(PlayerCharacter& pc) {
    // calculate damage
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
    std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
    return msg;
}

void Human::dropGold(PlayerCharacter& pc) {
    pc.addGold(4);
    gold_carried.clear();
}

void Human::takeDamage(int damage) {
    if (getHP() - damage <= 0) {
        setHP(0); // dead 
    }
    else {
        setHP(getHP() - damage);
    }
} 

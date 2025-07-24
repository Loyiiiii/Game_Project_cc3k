#include "Human.h"
#include "PlayerCharacter.h"
#include "NormalGold.h"

Human::Human(Position pos) :
    Enemy{ pos, 140, 20, 20, true, true, 'H' } {
    gold_carried.emplace_back(std::make_unique<NormalGold>());
    gold_carried.emplace_back(std::make_unique<NormalGold>());
}

Human::~Human() {}

void Human::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(getAtk(), pc.getDef());
    pc.takeDamage(damage);
}

void Human::dropGold(PlayerCharacter& pc) {
    pc.addGold(4);
    gold_carried.clear();
}

void Human::takeDamage(int damage) {
    if (getHP() - damage <= 0) {
        setHP(0);
    }
    else {
        setHP(getHP() - damage);
    }
} 
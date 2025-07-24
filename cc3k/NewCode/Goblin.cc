#include "Goblin.h"
#include "Enemy.h"

void Goblin::StealGold() {
    addGold(5);
}

Goblin::Goblin() :
    PlayerCharacter{ 110, 110, 15, 20, 0, Race::GOBLIN, true } {}

void Goblin::attack(Enemy& e) {
    PlayerCharacter::attack(e);
    if (e.getHP() <= 0) {
        StealGold();
    }
} 
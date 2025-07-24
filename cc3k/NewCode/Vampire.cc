#include "Vampire.h"
#include "Enemy.h"

void Vampire::gainHP() {
    setHP(getHP() + 5);
}

Vampire::Vampire() :
    PlayerCharacter{ 50, -1, 25, 25, 0, Race::VAMPIRE, false } {}

void Vampire::attack(Enemy& enemy) {
    if (enemy.getSymbol() == 'W') { // Dwarf
        takeDamage(5);
    }
    else {
        gainHP();
    }
    PlayerCharacter::attack(enemy);
} 
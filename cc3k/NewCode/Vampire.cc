#include "Vampire.h"
#include "Enemy.h"

void Vampire::gainHP() {
    setHP(getHP() + 5); // adds 5 HP to the vampire
}

Vampire::Vampire() :
    // superclass ctor runs
    // set the max health to be -1, so that the vampire does not have a max health
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

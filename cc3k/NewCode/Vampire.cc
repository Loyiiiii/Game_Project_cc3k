#include "Vampire.h"
#include "Enemy.h"

void Vampire::gainHP() {
    setHP(getHP() + 5); // adds 5 HP to the vampire
}

Vampire::Vampire() :
    // superclass ctor runs
    // set the max health to be -1, so that the vampire does not have a max health
    PlayerCharacter{ 50, -1, 25, 25, 0, Race::VAMPIRE, false } {}

std::string Vampire::attack(Enemy& enemy) {
    std::string retval;
    if (enemy.getSymbol() == 'W') { // Dwarf
        takeDamage(5);
        retval = "Vampire attacks Dwarf and loses 5 HP. ";
    }
    else {
        gainHP();
        retval = "Vampire gains 5 HP. ";
    }
    std::string msg = PlayerCharacter::attack(enemy) + retval;
    return msg;
} 

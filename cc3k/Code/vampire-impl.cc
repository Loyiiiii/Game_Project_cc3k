module Vampire;
import PlayerCharacter; // For PlayerCharacter
import Enemy;           // For Enemy
import Global_Constants; // for Race enum

void Vampire::gainHP() {
    if (health < maxHealth) {
        health +=5;
    }
    else {
        maxHealth = health + 5;
        health = maxHealth;
    }
}

Vampire::Vampire():
    PlayerCharacter{50, 50, 25, 25, 0, Race::VAMPIRE, false} {}

void Vampire::attack(Enemy& enemy) {
    // if encounters a dwarf, lose 5HP instead of gaining 5HP; 
    if (enemy.getSymbol() == 'D') {
        takeDamage(5);
    }
    else {
        gainHP();
    }
    PlayerCharacter::attack(enemy);
}

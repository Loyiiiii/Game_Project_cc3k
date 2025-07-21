module Vampire;

void Vampire::gainHP() {
    if (health < maxHealth) {
        health +=5;
    }
    else {
        maxHealth = health + 5;
        health = maxHealth;
    }
}

Vampire::Vampire(Position pos):
    PlayerCharacter(pos, 50, 50, 25, 25, 0, Race::VAMPIRE, false) {}

void Vampire::attack(Enemy& enemy) {
    gainHP();
    // needs to check if we are attacking a dwarf -> lose 5HP
    PlayerCharacter::attack(enemy);
}

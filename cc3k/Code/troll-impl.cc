module Troll;

void Troll::gainHP() {
    // may never exceed 120 HP
    if (health + 5 > 120) {
        health = 120;
    }
    else {
        health +=5;
    }
}

Troll::Troll(Position pos):
    PlayerCharacter(pos, 120, 120,25,15, 0, Race::TROLL) {}

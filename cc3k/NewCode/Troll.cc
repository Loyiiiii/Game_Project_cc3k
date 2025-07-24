#include "Troll.h"

Troll::Troll() :
    PlayerCharacter{ 120, 120, 25, 15, 0, Race::TROLL, true } {}

void Troll::gainHP() {
    if (getHP() + 5 > 120) {
        setHP(120);
    }
    else {
        setHP(getHP() + 5);
    }
} 
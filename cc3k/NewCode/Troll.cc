#include "Troll.h"

Troll::Troll() :
    // superclass ctor runs
    PlayerCharacter{ 120, 120, 25, 15, 0, Race::TROLL, true } {}


void Troll::gainHP() {
    // may not exceed 120 HP -> its MAX HP
    if (getHP() + 5 > 120) {
        setHP(120);
    }
    else {
        setHP(getHP() + 5);
    }
} 

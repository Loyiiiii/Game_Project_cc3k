module Troll;
import PlayerCharacter;
import Global_Constants;

void Troll::gainHP() {
    // may never exceed 120 HP
    if (health + 5 > 120) {
        health = 120;
    }
    else {
        health +=5;
    }
}
// remember to add 5HP every turn. 
Troll::Troll():
    PlayerCharacter{120, 120, 25, 15, 0, Race::TROLL, true} {}

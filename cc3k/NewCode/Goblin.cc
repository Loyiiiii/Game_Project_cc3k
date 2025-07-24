#include "Goblin.h"
#include "Enemy.h"

void Goblin::StealGold() {
    addGold(5); // add 5 gold
}


Goblin::Goblin() :
    // superclass ctor runs 
    PlayerCharacter{ 110, 110, 15, 20, 0, Race::GOBLIN, true } {}


std::string Goblin::attack(Enemy& e) {
    std::string msg = PlayerCharacter::attack(e);
    // check if the enemy is dead
    if (e.getHP() <= 0) {
        StealGold(); // steal 5 gold from the enemy
        msg += " Goblin steals 5 gold!";
    }
    return msg;
} 

module Goblin;
import PlayerCharacter;
import Global_Constants;

void Goblin::StealGold() {
    goldATM += 5;
}

Goblin::Goblin():
    PlayerCharacter{110, 110, 15, 20, 0, Race::GOBLIN, true} {}


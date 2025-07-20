module Goblin;

void Goblin::StealGold() {
    goldATM += 5;
}

Goblin::Goblin(Position pos):
    PlayerCharacter(pos, 110, 110, 15, 20, 0, Race::GOBLIN) {}


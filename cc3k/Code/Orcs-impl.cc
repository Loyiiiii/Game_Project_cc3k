module Orcs;
import Enemy;
import PlayerCharacter;
import Global_Constants;

// Orcs: 180HP, 30Atk, 25Def.
// deals 50% more damage to goblins
Orcs::Orcs(Position pos):
    Enemy{pos, 180, 30, 25, true, true, 'O'} {}

void Orcs::attack(PlayerCharacter& pc) {
    int normal_damage = calculateDamage(this->Atk, pc.getDef());
    // check if attacking goblin.
    if (pc.getRace() == Race::GOBLIN) {
        // damage is done * 50%. 
        int augmented_dmg = normal_damage * 1.5;
        pc.takeDamage(augmented_dmg);
    }
    else {
        pc.takeDamage(normal_damage);
    }
}

void Orcs::dropGold(PlayerCharacter& pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2; // 0 or 1
    int value = (randomNum == 0) ? 1 : 2; // 1: small gold, 2: normal gold
    pc.addGold(value); // need to figure out how to get the PC here. 
}

void Orcs::takeDamage(int dmg) {
    if(HP - dmg <= 0) {
        HP = 0; // dead
    }
    else {
        HP -= dmg;
    }
}

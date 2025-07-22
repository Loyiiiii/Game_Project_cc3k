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

void Orcs::dropGold() {
    pc.addGold(2); // need to figure out how to get the PC here. 
}

void Orcs::takeDamage(int dmg) {
    if(HP - dmg < 0) {
        HP = 0; // dead
        // gold is automatically added to PC.
        dropGold();
    }
    else {
        HP -= dmg;
    }
}

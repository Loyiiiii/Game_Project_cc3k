module Human; 
import <memory>;
import NormalGold;
import Enemy;
import Global_Constants;
import PlayerCharacter;

// Human: 140HP, 20Atk, 20Def, - drops 2 normal piles when dead
Human::Human(Position pos):
    Enemy(pos, 140, 20, 20, true, true, 'H') {
        gold_carried.emplace_back(std::make_unique<NormalGold>());
        gold_carried.emplace_back(std::make_unique<NormalGold>());
    }

Human::~Human() {}

void Human::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Human::dropGold() {
    // Transfer gold to game world (placeholder - needs GameWorld integration)
    for (auto& gold : gold_carried) {
        // GameWorld::addGold(std::move(gold), this->pos);
        // For now, just release the gold objects
    }
    gold_carried.clear(); // Human no longer carries gold
}

void Human::takeDamage(int damage) {
    if (HP - damage <= 0) {
        HP = 0; // dead
        // drop gold:
        dropGold();
    }
    else {
        HP -= damage;
    }
}

char Human::getSymbol() {
    return 'H';
}

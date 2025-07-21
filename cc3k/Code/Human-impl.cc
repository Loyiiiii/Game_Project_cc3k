module Human; 
import <memory>;
import NormalGold;
import Enemy;
import Global_Constants;
import PlayerCharacter;

Human::Human(Position pos, int health, int damage, int defense, bool movable):
    Enemy(pos, health, damage, defense, movable) {
        gold_carried.emplace_back(std::make_unique<NormalGold>());
        gold_carried.emplace_back(std::make_unique<NormalGold>());
    }

Human::~Human() {}

void Human::attack(PlayerCharacter& pc) {
    pc.takeDamage(Atk);
}

void Human::dropGold() {
    // drop 2 gold
    gold_carried.pop_back();
    gold_carried.pop_back();
}

void Human::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0; // dead
        // drop gold:
        dropGold();
    }
    else {
        HP -= damage;
    }
}

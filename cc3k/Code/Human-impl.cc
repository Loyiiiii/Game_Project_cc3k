module Human; 
import <memory>;
import NormalGold;
import Enemy;
import Global_Constants;
import PlayerCharacter;

// Human: 140HP, 20Atk, 20Def, - drops 2 normal piles when dead
Human::Human(Position pos):
    Enemy(pos, 140, 20, 20, true) {
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

char Human::getSymbol() {
    return 'H';
}

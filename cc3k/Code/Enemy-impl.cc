module Enemy;
import <cmath>;
import Global_Constants;
import PlayerCharacter;

Enemy::Enemy(Position pos, int health, int damage, int defense, bool movable):
pos{pos}, HP{health}, Atk{damage}, Def{defense}, movable{movable} {}

Enemy::~Enemy() {}

bool Enemy::is_alive() {
    return HP > 0;
}

// Getters. 
int Enemy::getAtk() {
    return Atk;
}
int Enemy::getDef() {
    return Def;
}

int Enemy::getHP() {
    return HP;
}

int Enemy::calculateDamage(int attackerAtk, int defenderDef) {
    // ceiling((100/(100 + Def (Defender))) * Atk(Attacker))
    float ratio = 100.0 / (100.0 + defenderDef);  // Float precision
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
}

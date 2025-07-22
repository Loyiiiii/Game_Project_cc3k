module Enemy;
import <cmath>;
import Global_Constants;
import PlayerCharacter;

Enemy::Enemy(Position pos, int health, int damage, int defense, bool movable, bool is_neutral, char symbol):
    HP{health}, Atk{damage}, Def{defense}, pos{pos}, movable{movable}, is_neutral{is_neutral}, symbol{symbol} {}

Enemy::~Enemy() {}

bool Enemy::is_alive() const{
    return HP > 0;
}

char Enemy::getSymbol() const {
    return symbol;
}
// Getters. 
int Enemy::getAtk() const {
    return Atk;
}
int Enemy::getDef() const {
    return Def;
}

int Enemy::getHP() const {
    return HP;
}

int Enemy::calculateDamage(int attackerAtk, int defenderDef) {
    // ceiling((100/(100 + Def (Defender))) * Atk(Attacker))
    float ratio = 100.0 / (100.0 + defenderDef);  // Float precision
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
}

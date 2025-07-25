#include "Enemy.h"
#include <cmath>

Enemy::Enemy(Position pos, int health, int damage, int defense, bool movable, bool is_neutral, char symbol) :
    pos{ pos }, HP{ health }, Atk{ damage }, Def{ defense }, movable{ movable }, is_neutral{ is_neutral }, symbol{ symbol } {}

Enemy::~Enemy() {}

bool Enemy::is_alive() const {
    return HP > 0;
}

char Enemy::getSymbol() const {
    return symbol;
}

int Enemy::getAtk() const {
    return Atk;
}

int Enemy::getDef() const {
    return Def;
}

int Enemy::getHP() const {
    return HP;
}

void Enemy::setHP(int hp) {
    HP = hp;
}

void Enemy::setMovable(bool isMovable) { movable = isMovable; }

bool Enemy::isAdjacentTo(const Position& pc_pos) const {
    Position enemy_pos = this->pos;
    int row_diff = std::abs(enemy_pos.row - pc_pos.row);
    int col_diff = std::abs(enemy_pos.col - pc_pos.col);
    return (row_diff <= 1 && col_diff <= 1 && (row_diff != 0 || col_diff != 0));
}

bool Enemy::getMoveStatus() const {
    return movable;
}

Position Enemy::getPosition() const {
    return pos;
}

void Enemy::setPosition(Position newPos) {
    this->pos = newPos;
}

int Enemy::calculateDamage(int attackerAtk, int defenderDef) {
    float ratio = 100.0 / (100.0 + defenderDef);
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
} 

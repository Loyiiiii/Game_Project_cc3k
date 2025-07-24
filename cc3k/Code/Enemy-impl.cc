module Enemy;
import <cmath>;
import Global_Constants;
import PlayerCharacter;
// Forward declaration instead of import

Enemy::Enemy(Position pos, int health, int damage, int defense, bool movable, bool is_neutral, char symbol):
    pos{pos}, HP{health}, Atk{damage}, Def{defense}, movable{movable}, is_neutral{is_neutral}, symbol{symbol} {}

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


bool Enemy::isAdjacentTo(const PlayerCharacter& pc, const Position& enemy_pos) const {

    Position enemy_pos = this->pos; 
    // check if the player is adjacent to the enemy // within a 1-cell distance
    int row_diff = std::abs(player_pos.row - enemy_pos.row);
    int col_diff = std::abs(player_pos.col - enemy_pos.col);
    if (row_diff <= 1 && col_diff <= 1 && (row_diff != 0 || col_diff != 0)) {
        return true; 
    }
    return false;
}

bool Enemy::getMoveStatus() const{
    return movable;
}

Position Enemy::getPosition() const {
    return pos;
}

void Enemy::setPosition(Position newPos) {
    this->pos = newPos;
}

int Enemy::calculateDamage(int attackerAtk, int defenderDef) {
    // ceiling((100/(100 + Def (Defender))) * Atk(Attacker))
    float ratio = 100.0 / (100.0 + defenderDef);  // Float precision
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
}

module Enemy;
import Global_Constants;
import PlayerCharacter;

Enemy::Enemy(Position pos, int health, int damage, int defense, bool movable):
    HP{health}, Atk{damage}, Def{defense}, pos{pos}, movable{movable} {}

Enemy::~Enemy() {}

bool Enemy::is_alive() {
    return HP > 0;
}

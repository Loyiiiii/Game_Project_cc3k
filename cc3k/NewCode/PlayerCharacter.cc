#include "PlayerCharacter.h"
#include <cmath>
#include "Enemy.h"

PlayerCharacter::PlayerCharacter(int health, int maxHealth,
    int atk, int def, int gold, Race race, bool has_max_health) :
    pos{ -1, -1 }, health{ health }, maxHealth{ maxHealth }, atk{ atk }, def{ def },
    goldATM{ gold }, race{ race }, has_max_health{ has_max_health } {}

PlayerCharacter::~PlayerCharacter() {}

void PlayerCharacter::drinkPotion(Potion& p) {
    PotionInUse.push_back(p);
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        if (has_max_health) {
            if (health + p.getAmount() > maxHealth) {
                health = maxHealth;
            }
            else {
                health += p.getAmount();
            }
        }
        else {
            health += p.getAmount();
        }
    }
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        atk += p.getAmount();
    }
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        def += p.getAmount();
    }
    else if (p.getType() == Potion_Type::POISON_HEALTH) {
        if (health + p.getAmount() < 0) {
            health = 0;
        }
        else {
            health += p.getAmount();
        }
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        atk += p.getAmount();
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        def += p.getAmount();
    }
}

Position PlayerCharacter::getPosition() const { return pos; }
int PlayerCharacter::getHP() const { return health; }
void PlayerCharacter::setHP(int hp) { health = hp; }
int PlayerCharacter::getMaxHP() const { return maxHealth; }
bool PlayerCharacter::hasMaxHealth() const { return has_max_health; }
int PlayerCharacter::getAtk() const { return atk; }
void PlayerCharacter::setAtk(int new_atk) { atk = new_atk; }
int PlayerCharacter::getDef() const { return def; }
void PlayerCharacter::setDef(int new_def) { def = new_def; }
int PlayerCharacter::getGold() const { return goldATM; }
Race PlayerCharacter::getRace() const { return race; }
void PlayerCharacter::addGold(int amount) { goldATM += amount; }

int PlayerCharacter::calculateDamage(int attackerAtk, int defenderDef) {
    float ratio = 100.0 / (100.0 + defenderDef);
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
}

void PlayerCharacter::attack(Enemy& enemy) {
    int damage = calculateDamage(this->atk, enemy.getDef());
    enemy.takeDamage(damage);
    if (!enemy.is_alive()) {
        enemy.dropGold(*this);
    }
}

void PlayerCharacter::takeDamage(int damage) {
    if (health - damage < 0) {
        health = 0;
    }
    else {
        health -= damage;
    }
}

void PlayerCharacter::setPosition(Position newPos) {
    this->pos = newPos;
}

bool PlayerCharacter::isDead() const {
    return health <= 0;
} 
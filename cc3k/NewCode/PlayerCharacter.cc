#include "PlayerCharacter.h"
#include <cmath>
#include <string>
#include "Enemy.h"

PlayerCharacter::PlayerCharacter(int health, int maxHealth,
    int atk, int def, int gold, Race race, bool has_max_health) :
    // we set the default position to be (-1, -1) - later on to be changed once floor selects its random position
    pos{-1, -1}, health{health}, maxHealth{maxHealth}, atk{atk}, def{def},
    goldATM{gold}, race{race}, has_max_health{has_max_health} {}

PlayerCharacter::~PlayerCharacter() {}

void PlayerCharacter::drinkPotion(Potion& p) {
    PotionInUse.push_back(p); // add the potion to the effect in use list
    // Positive Effects: 
    // HEALTH_RESTORE
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        if (has_max_health) {
            if (health + p.getAmount() > maxHealth) {
                health = maxHealth; // set to max
            }
            else {
                health += p.getAmount(); // add the amount 
            }
        }
        else {
            health += p.getAmount(); // add the amount 
        }
    }
    // ATK_BOOST
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        atk += p.getAmount(); // add the amount 
    }
    // DEF_BOOST
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        def += p.getAmount();
    }
    // Negative Effects: 
    // POISON_HEALTH
    else if (p.getType() == Potion_Type::POISON_HEALTH) {
        if (health + p.getAmount() < 0) {
            health = 0; // set to 0 -> pc is dead
        }
        else {
            health += p.getAmount(); // add the amount 
        }
    }
    // WOUND_ATK
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        atk += p.getAmount(); // add the negative effect: the potion will add -5 atk
    }
    // WOUND_DEF
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        def += p.getAmount(); // add the negative effect: the potion will add -5 def
    }
}
// getters:
Position PlayerCharacter::getPosition() const {
    return pos;
}
int PlayerCharacter::getHP() const {
    return health;
}
int PlayerCharacter::getMaxHP() const {
    return maxHealth;
}
bool PlayerCharacter::hasMaxHealth() const {
    return has_max_health;
}
int PlayerCharacter::getAtk() const {
    return atk;
}
int PlayerCharacter::getDef() const {
    return def;
}
int PlayerCharacter::getGold() const {
    return goldATM;
}
Race PlayerCharacter::getRace() const {
    return race;
}
// setters:
void PlayerCharacter::addGold(int amount) {
    goldATM += amount;
}

void PlayerCharacter::setHP(int hp) {
    health = hp;
}

void PlayerCharacter::setAtk(int new_atk) {
    atk = new_atk;
}

void PlayerCharacter::setDef(int new_def) {
    def = new_def;
}

// calculate the damage that the PC deals to the enemy
int PlayerCharacter::calculateDamage(int attackerAtk, int defenderDef) {
    float ratio = 100.0 / (100.0 + defenderDef);
    float damage = ratio * attackerAtk;
    return static_cast<int>(std::ceil(damage)); // cast to an int 
}

// Virtual Methods that can be overridden by subclasses
std::string PlayerCharacter::attack(Enemy& enemy) {
     // Calculate damage using proper formula
    int damage = calculateDamage(this->atk, enemy.getDef());
    enemy.takeDamage(damage); // enemy takes damage
    std::string msg = "PC deals " + std::to_string(damage) + " to " + std::string(1, enemy.getSymbol())
                      + "(" + std::to_string(enemy.getHP()) + "). ";
    if (!enemy.is_alive()) {
        enemy.dropGold(*this);
        msg += std::string(1, enemy.getSymbol()) + " is slain!";
    }
    return msg;
}

void PlayerCharacter::takeDamage(int damage) {
    // use getters and setters to update the health
    if (this->getHP() - damage < 0) {
        this->setHP(0);
    }
    else {
        this->setHP(this->getHP() - damage);
    }
}

void PlayerCharacter::setPosition(Position newPos) {
    this->pos = newPos;
}

bool PlayerCharacter::isDead() const {
    return this->getHP() <= 0;
}

void PlayerCharacter::clearTempPotionEffects() {
    // clear the temporary potion effects
    PotionInUse.clear();
    // reset the stats to the base values (default atk and def)
    // we know that the HP is not affected by the potion effects
    switch (race) {
        case Race::SHADE:
            setAtk(25);
            setDef(25);
            break;
        case Race::DROW:
            setAtk(25);
            setDef(15);
            break;
        case Race::VAMPIRE:
            setAtk(25);
            setDef(25);
            break;
        case Race::TROLL:
            setAtk(25);
            setDef(15);
            break;
        case Race::GOBLIN:
            setAtk(15);
            setDef(20);
            break;
        default:
            break;
    }
}

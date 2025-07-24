module PlayerCharacter;
import <cmath>;
import <vector>;
import Global_Constants;
// Forward declaration instead of import
class Enemy;
import position;

// New constructor: Initializes position to an invalid state {-1, -1}
PlayerCharacter::PlayerCharacter(int health, int maxHealth, 
    int atk, int def, int gold, Race race, bool has_max_health):
    pos{-1, -1}, health{health}, maxHealth{maxHealth}, atk{atk}, def{def},
    goldATM{gold}, race{race}, has_max_health{has_max_health} {}


PlayerCharacter::~PlayerCharacter() {}

void PlayerCharacter::drinkPotion(Potion& p) {
    PotionInUse.emplace(p); // first add to the vector. 
    // Positive effects:
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        if (has_max_health == true) {
            // for other races:
            // can not exceed max health 
            if (health + p.getAmount() > maxHealth) {
                health = maxHealth;
            }
            else {
                health += p.getAmount();
            }
        }
        else {
            // vampire
            health += p.getAmount();
            
        }
    }
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        atk += p.getAmount();
    }
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        def += p.getAmount();
    }
    // Negative effects:
    else if (p.getType() == Potion_Type::POISION_HEALTH) {
        if (health - p.getAmount() < 0) {
            health = 0;  // can't be negative -> the PC is dead.
        }
        else {
            health += p.getAmount(); // we will add the negative effect - the potion will -10 HP.
        }
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        atk += p.getAmount(); // we will add the negative effect - the potion will -5 Atk.
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        def += p.getAmount(); // we will add the negative effect - the potion will -5 Def.
    }
}

// Some Getters:
Position PlayerCharacter::getPosition() const {
    return pos;
}

int PlayerCharacter::getHealth() const {
    return health;
}

int PlayerCharacter::getMaxHealth() const {
    return maxHealth;
}

bool PlayerCharacter::HasMaxHealth() const {
    return has_max_health;
}

int PlayerCharacter::getAtk() const {
    return atk;
}

int PlayerCharacter::getDef() const {
    return def;
}

int PlayerCharacter::getGoldATM() const {
    return goldATM;
}

Race PlayerCharacter::getRace() const {
    return race; 
}

void PlayerCharacter::addGold(int amount) {
    goldATM += amount;
}

// damage calculation:
int PlayerCharacter::calculateDamage(int attackerAtk, int defenderDef) {
    // ceiling((100/(100 + Def (Defender))) * Atk(Attacker))
    float ratio = 100.0 / (100.0 + defenderDef);  // Float precision
    float damage = ratio * attackerAtk;
    return int(std::ceil(damage));
}


// Virtual Methods that can be overridden by subclasses
void PlayerCharacter::attack(Enemy& enemy) {
    // Calculate damage using proper formula
    int damage = calculateDamage(this->atk, enemy.getDef());
    enemy.takeDamage(damage);
    // check if enemy is dead - we will add gold to PC here. 
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
    this->pos = newPos; // setting the position of the PC.
}

bool PlayerCharacter::isDead(){
    return health <= 0;
}
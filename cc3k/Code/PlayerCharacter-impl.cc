module PlayerCharacter;

PlayerCharacter::PlayerCharacter(Position pos, int health, int maxHealth, 
    int atk, int def, int gold, Race race, bool has_max_health):
    pos{pos}, health{health}, maxHealth{maxHealth}, atk{atk}, def{def},
    goldATM{gold}, race{race}, has_max_health{has_max_health} {}


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
Position PlayerCharacter::getPos() {
    return pos;
}

int PlayerCharacter::getHealth() {
    return health;
}

int PlayerCharacter::getMaxHealth() {
    return maxHealth;
}

bool PlayerCharacter::HasMaxHealth() {
    return has_max_health;
}

int PlayerCharacter::getAtk() {
    return atk;
}

int PlayerCharacter::getDef() {
    return def;
}

int PlayerCharacter::getGoldATM(){
    return goldATM;
}

Race PlayerCharacter::getRace() {
    return race; 
}

// Virtual Methods that can be overridden by subclasses

void PlayerCharacter::attack(Enemy& enemy) {
    // this just deal this->atk damage to the enemy.
    enemy.takeDamage(atk); // enemy will take damage. 
}

void PlayerCharacter::takeDamage(int damage) {
    if (health - damage < 0) {
        health = 0;
    }
    else {
        health -= damage;
    }
}
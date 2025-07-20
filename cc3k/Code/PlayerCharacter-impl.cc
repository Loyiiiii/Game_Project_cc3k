module PlayerCharacter;

PlayerCharacter::PlayerCharacter(Position pos, int health, int maxHealth, 
    int atk, int def, int gold, Race race, bool has_max_health):
    pos{pos}, health{health}, maxHealth{maxHealth}, atk{atk}, def{def},
    goldATM{gold}, race{race}, has_max_health{has_max_health} {}


void PlayerCharacter::drinkPotion(Potion p) {
    // Positive effects:
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        // ...
    }
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        // ...
    }
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        // ...
    }
    // Negative effects:
    else if (p.getType() == Potion_Type::POISION_HEALTH) {
        // ...
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        // ...
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        // ...
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
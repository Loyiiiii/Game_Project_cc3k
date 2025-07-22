module halfling;

Halfling::Halfling(Position pos): Enemy{pos, 100, 15, 20, true, true, 'L'} {}

void Halfling::attack(PlayerCharacter &pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Halfling::dropGold(PlayerCharacter &pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2; // 0 or 1
    int value = (randomNum % 2 == 0) ? 1 : 2; // 1 for small gold, 2 for normal gold
    pc.addGold(value);
}

void Halfling::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0; // Ensure HP does not go below 0
    } else {
        HP -= damage;
    }
}

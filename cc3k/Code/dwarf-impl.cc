module dwarf;

Dwarf::Dwarf(Position pos): 
    Enemy{pos, 100, 20, 30, true, true, 'W'} {}

// note: attack needs to incorporate damage calculation logic.
void Dwarf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Dwarf::dropGold(PlayerCharacter& pc) {
    // 50% small gold, 50% normal gold
    int randomNum = rand() % 2; // 0 or 1
    int value = (randomNum % 2 == 0) ? 1 : 2; // 1 for small gold, 2 for normal gold
    pc.addGold(value); // Assuming Dwarf drops 1 gold, may change it to randomly chosen between small and normal
}

void Dwarf::takeDamage(int damage) {
    if (HP - damage <= 0) {
        HP = 0;
    } else {
        HP -= damage;
    }
}


module dwarf;

Dwarf::Dwarf(Position pos): 
    Enemy{Pos, 100, 20, 30, true, true, 'W'} {}

// note: attack needs to incorporate damage calculation logic.
void Dwarf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Dwarf::dropGold(PlayerCharacter& pc) {
    pc.addGold(1); // Assuming Dwarf drops 1 gold, may change it to randomly chosen between small and normal
}

void Dwarf::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0;
    } else {
        HP -= damage;
    }
}


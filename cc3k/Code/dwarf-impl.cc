module dwarf;

Dwarf::Dwarf(Position pos): 
    Enemy{Pos, 100, 20, 30, true, true, 'W'} {}

// note: attack needs to incorporate damage calculation logic.
void Dwarf::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Dwarf::dropGold(int goldAmount) {
    pc.addGold(goldAmount); // Assuming Dwarf drops 1 gold, may change it to randomly chosen between small and normal
}

char Dwarf::getSymbol() {
    return symbol;
}

void Dwarf::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0;
    } else {
        HP -= damage;
    }
}

bool Dwarf::is_alive() {
    return HP > 0;
}

int Dwarf::getAtk() {
    return Atk;
}

int Dwarf::getDef() {
    return Def;
}

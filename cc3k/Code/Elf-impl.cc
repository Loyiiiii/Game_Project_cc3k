module elf;

Elf::Elf(Position pos, int HP, int Atk, int Def, bool movable, bool is_neutral):
    Enemy{pos, 140, 30, 10, true, true 'E'} {}

void Elf::attack(PlayerCharacter& pc) {
    // check if player is Drow
    if (pc.getRace() == Race::DROW) {
        // One attack
        int damage = calculateDamage(this->Atk, pc.getDef());
        pc.takeDamage(damage);
    } else {
        // Two attacks
        for (int i = 0; i < 2; i++) {
            int damage = calculateDamage(this->Atk, pc.getDef());
            pc.takeDamage(damage);
        }
    }
}

void Elf::dropGold(PlayerCharacter& pc) {
    pc.addGold(1); // Assuming Elf drops 1 gold, may change it to randomly chosen between small and normal
}

char Elf::getSymbol() {
    return symbol;
}

void Elf::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0;
    } else {
        HP -= damage;
    }
}

bool Elf::is_alive() {
    return HP > 0;
}

int Elf::getAtk() {
    return Atk;
}

int Elf::getDef() {
    return Def;
}

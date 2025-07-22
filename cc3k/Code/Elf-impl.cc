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
    int randomNum_gold = rand() % 2; // 0 or 1
    int value = (randomNum == 0) ? 1 : 2; // 1 for small gold, 2 for normal gold
    pc.addGold(value); // Assuming Elf drops 1 gold, may change it to randomly chosen between small and normal
}

void Elf::takeDamage(int damage) {
    if (HP - damage < 0) {
        HP = 0;
    } else {
        HP -= damage;
    }
}


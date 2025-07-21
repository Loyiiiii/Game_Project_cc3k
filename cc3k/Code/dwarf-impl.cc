module dwarf;

Dwarf::Dwarf(Position pos, int HP, int Atk, int Def, bool movable, char symbol): 
    Enemy{Pos, HP, Atk, Def, movable}, symbol{'W'} {}

// note: attack needs to incorporate damage calculation logic.
void Dwarf::attack(PlayerCharacter& pc) {
    
}

void Dwarf::dropGold() {

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

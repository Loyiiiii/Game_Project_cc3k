module Cell;

Cell::Cell(char symbol, int row, int col): 
    symbol{symbol}, pos{row, col}, pc{nullptr}, e{nullptr}, p{nullptr} {}

char Cell::getSymbol() {
    if (pc) {
        return pc->symbol;
    } else if (e) {
        return e->symbol;
    } else if (p) {
        return p->symbol;
    } else {
        return symbol;
    }
}

void Cell::setSymbol(char sym) {
    symbol = sym;
}

void Cell::placeCharacter(PlayerCharacter *pc) {
    pc = pc;
}

void Cell::removeCharacter() {
    pc = nullptr;
}

void Cell::placeEnemy(Enemy *e) {
    e = e;
}

void Cell::removeEnemy() {
    e = nullptr;
}

void Cell::placePotion(Potion *p) {
    p = p;
}

void removePotion() {
    p = nullptr;
}

module Cell;

Cell::Cell(char symbol, int row, int col): baseSymbol{symbol}, row{row}, col{col} {}


void Cell::placeCharacter(PlayerCharacter *pc) { pc = pc; }

void Cell::removeCharacter() { pc = nullptr; }

void Cell::placeEnemy(Enemy *e) { e = e; }

void Cell::removeEnemy() { e = nullptr; }

void Cell::placeItem(Item *i) { i = i; }

void Cell::removeItem() { p = nullptr; }

char Cell::getSymbol() {
    if (pc) {
        return '@';
    } else if (e) {
        return e->getSymbol();
    } else if (p) {
        return p->getSymbol();
    } else {
        return symbol;
    }
}

char Cell::getBaseSymbol() const { return baseSymbol; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }

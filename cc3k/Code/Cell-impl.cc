module Cell;

Cell::Cell(char symbol, int row, int col, bool isPassable): 
    baseSymbol{symbol}, row{row}, col{col}, isPassable{isPassable} {}


void Cell::placeCharacter(PlayerCharacter *pc) { pc = pc; }

void Cell::removeCharacter() { pc = nullptr; }

void Cell::placeEnemy(Enemy *e) { e = e; }

void Cell::removeEnemy() { e = nullptr; }

void Cell::placePotion(Potion *p) { p = p; }

void Cell::removePotion() { p = nullptr; }

void Cell::placeGold(Gold *g) { g = g; }

void Cell::removeGold() { g = nullptr; }

char Cell::getSymbol() {
    if (pc) {
        return '@';
    } else if (e) {
        return e->getSymbol();
    } else if (p) {
        return p->getSymbol();
    } else if (g) {
        return g->symbol();
    } else {
        return baseSymbol;
    }
}
char Cell::getBaseSymbol() const { return baseSymbol; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
void Cell::setSymbol(char symbol) { baseSymbol = symbol; }

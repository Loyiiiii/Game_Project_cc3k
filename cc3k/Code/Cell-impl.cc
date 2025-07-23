module Cell;
import gold; // Need to import so we can dynamic_cast
import Potion; // Need to import so we can dynamic_cast

Cell::Cell(char symbol, int row, int col, bool isPassable): 
    baseSymbol{symbol}, row{row}, col{col}, isPassable{isPassable} {}


void Cell::placeCharacter(PlayerCharacter *pc) { this->pc = pc; }

void Cell::removeCharacter() { this->pc = nullptr; }

void Cell::placeEnemy(Enemy *e) { this->e = e; }

void Cell::removeEnemy() { this->e = nullptr; }

void Cell::placeItem(Item *i) { this->i = i; }

void Cell::removeItem() { this->i = nullptr; }

char Cell::getSymbol() const {
    if (pc) {
        return '@';
    } else if (e) {
        return e->getSymbol();
    } else if (i) {
        // We need to figure out if the item is Gold or a Potion
        if (auto gold_ptr = dynamic_cast<Gold*>(i)) {
            return gold_ptr->getSymbol();
        } else if (auto potion_ptr = dynamic_cast<Potion*>(i)) {
            return potion_ptr->getSymbol();
        }
    }
    return baseSymbol;
}
char Cell::getBaseSymbol() const { return baseSymbol; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
void Cell::setSymbol(char symbol) { baseSymbol = symbol; }

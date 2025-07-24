#include "Cell.h"
#include "Gold.h"
#include "Potion.h"
#include "Enemy.h"
#include "PlayerCharacter.h"

Cell::Cell(char symbol, int row, int col, bool isPassable): 
    baseSymbol{symbol}, row{row}, col{col}, isPassable{isPassable}, pc{nullptr}, e{nullptr}, p{nullptr}, g{nullptr} {}


void Cell::placeCharacter(PlayerCharacter *pc) { this->pc = pc; }

void Cell::removeCharacter() { this->pc = nullptr; }

void Cell::placeEnemy(Enemy *e) { this->e = e; }

void Cell::removeEnemy() { this->e = nullptr; }

void Cell::placePotion(Potion *p) { this->p = p; }

void Cell::removePotion() { this->p = nullptr; }

void Cell::placeGold(Gold *g) { this->g = g; }

void Cell::removeGold() { this->g = nullptr; }

char Cell::getSymbol() const {
    if (pc) {
        return '@';
    } else if (e) {
        return e->getSymbol();
    } else if (p) {
        return p->getSymbol();
    } else if (g) {
        return g->getSymbol();
    } else {
        return baseSymbol;
    }
}
char Cell::getBaseSymbol() const { return baseSymbol; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
Enemy* Cell::getEnemy() const { return e; }
Potion* Cell::getPotion() const { return p; }
Gold* Cell::getGold() const { return g; }

void Cell::setSymbol(char symbol) { baseSymbol = symbol; }
void Cell::setIsPassable(bool isPassable) { this->isPassable = isPassable; } 

#ifndef CELL_H
#define CELL_H

#include "PlayerCharacter.h"
#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"
#include "Position.h"

class Cell {
    char baseSymbol;
    int row, col;
    bool isPassable;

    PlayerCharacter *pc;
    Enemy *e;
    Potion *p;
    Gold *g;

public:
    Cell(char symbol, int row, int col, bool isPassable);

    void placeCharacter(PlayerCharacter *pc);
    void removeCharacter();

    void placeEnemy(Enemy *e);
    void removeEnemy();

    void placePotion(Potion *p);
    void removePotion();

    void placeGold(Gold *g);
    void removeGold();

    char getSymbol() const;
    char getBaseSymbol() const;
    int getRow() const;
    int getCol() const;
    Enemy* getEnemy() const;
    Potion* getPotion() const;
    Gold* getGold() const;

    void setSymbol(char symbol);
    void setIsPassable(bool isPassable);
};

#endif 

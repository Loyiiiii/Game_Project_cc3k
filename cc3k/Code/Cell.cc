export module Cell;

import PlayerCharacter;
import Enemy;
import Potion;
import Global_Constants;
import Position;
import item;
import gold;

export class Cell {
    // what does this cell represent
    char baseSymbol;
    int row, col; // position of the cell
    bool isPassable; // whether the cell is passable

    PlayerCharacter *pc = nullptr; // whether a pc is stepping on this cell
    Enemy *e = nullptr; // whether an enemy is stepping on this cell
    Item *i = nullptr; // whether a potion is on this cell

public:
    Cell(char symbol, int row, int col, bool isPassable);

    // place or remove a character
    void placeCharacter(PlayerCharacter *pc);
    void removeCharacter();
    // place or remove a enemy
    void placeEnemy(Enemy *e);
    void removeEnemy();
    // place or remove an item (potion or gold)
    void placeItem(Item *i);
    void removeItem();

    // Getters
    char getSymbol() const;
    char getBaseSymbol() const;
    int getRow() const;
    int getCol() const;
    // Setters
    void setSymbol(char symbol);
};

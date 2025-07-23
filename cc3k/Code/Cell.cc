export module Cell;

import PlayerCharacter;
import Enemy;
import Potion;
import Global_Constants;
import position;
import gold;

export class Cell {
    // what does this cell represent
    char baseSymbol;
    int row, col; // position of the cell
    bool isPassable; // whether the cell is passable

    PlayerCharacter *pc = nullptr; // whether a pc is stepping on this cell
    Enemy *e = nullptr; // whether an enemy is stepping on this cell
    Potion *p = nullptr; // whether a potion is on this cell
    Gold *g = nullptr; // whether a gold pile is on this cell

public:
    Cell(char symbol, int row, int col, bool isPassable);

    // place or remove a character
    void placeCharacter(PlayerCharacter *pc);
    void removeCharacter();
    // place or remove a enemy
    void placeEnemy(Enemy *e);
    void removeEnemy();
    // place or remove a potion
    void placePotion(Potion *p);
    void removePotion();
    // place or remove a gold pile
    void placeGold(Gold *g);
    void removeGold();

    // Getters
    char getSymbol() const;
    char getBaseSymbol() const;
    int getRow() const;
    int getCol() const;
    Enemy* getEnemy() const;
    Potion* getPotion() const;
    Gold* getGold() const;
    // Setters
    void setSymbol(char symbol);
    void setIsPassable(bool isPassable);
};

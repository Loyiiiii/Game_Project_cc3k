export module Cell;

import PlayerCharacter;
import Enemy;
import Potion;
import Global_Constants;

export class Cell {
    // what does this cell represent
    char symbol;
    bool isPassable;
    Position pos;

    PlayerCharacter *pc; // whether a pc is stepping on this cell
    Enemy *e; // whether an enemy is stepping on this cell
    Potion *p; // whether a potion is on this cell

public:
    Cell(char symbol, int row, int col);

    char getSymbol();
    void setSymnol(char sym);
    bool getIsPassable();
    void setIsPassable(bool val);

    // place or remove a character
    void placeCharacter(PlayerCharacter *pc);
    void removeCharacter();
    // place or remove a enemy
    void placeEnemy(Enemy *e);
    void removeEnemy();
    // place or remove a potion
    void placePotion(Potion *p);
    void removePotion();
};

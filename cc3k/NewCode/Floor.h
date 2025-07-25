#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <memory>
#include <string>

#include "Cell.h"
#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"
#include "Position.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Floor {
    int numRows = 25;   // number of rows in the map
    int numCols = 79;   // number of columns in the map
    std::vector<std::vector<Cell>> map;     // 2D vector of Cell to store map
    Position stairPos;      // store the position of stairway

    // container for Enemy, Potion, and Gold
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Potion>> potions;
    std::vector<std::unique_ptr<Gold>> goldsPiles;

    // keep track of playercharacter
    PlayerCharacter* player;

public:
    Floor();

    // initialize the map with pc, stair, enemies, potions, gold randomly generated
    void floor_init(PlayerCharacter* pc, const std::string& filename);
    void printMap(PlayerCharacter* pc); // print the whole map onto screen

    // accessor
    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const; // get enemies
    const std::vector<std::unique_ptr<Potion>>& getPotions() const; // get potions
    const std::vector<std::unique_ptr<Gold>>& getGoldPiles() const; // get gold

    // move the playercharacter
    Position movePlayer(Position oldPos, Direction dir, bool& goldCollected);

    Cell& getTargetCell(int row, int col);  // return the cell at (row, col)
    Position getStairPos() const;   // return the position of stairway

    void moveRandom(Enemy* enemy);
};

#endif 

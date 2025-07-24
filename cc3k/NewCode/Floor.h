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
    int numRows = 25;
    int numCols = 79;
    std::vector<std::vector<Cell>> map;
    Position stairPos;

    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Potion>> potions;
    std::vector<std::unique_ptr<Gold>> goldsPiles;

    PlayerCharacter* player;

public:
    Floor();

    void floor_init(PlayerCharacter* pc, const std::string& filename);
    void printMap(PlayerCharacter* pc);

    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
    const std::vector<std::unique_ptr<Potion>>& getPotions() const;
    const std::vector<std::unique_ptr<Gold>>& getGoldPiles() const;

    Position movePlayer(Position oldPos, Direction dir);

    Cell& getTargetCell(int row, int col);
    Position getStairPos() const;

    void addGoldPile(std::unique_ptr<Gold> gold, Position pos);
    void moveRandom(Enemy* enemy);
};

#endif 
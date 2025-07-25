#include "Floor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <cstdlib>

#include "Cell.h"
#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"
#include "Position.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"
#include "RestoreHealth.h"
#include "BoostAtk.h"
#include "BoostDef.h"
#include "PoisonHealth.h"
#include "WoundAtk.h"
#include "WoundDef.h"
#include "NormalGold.h"
#include "Dragon.h"
#include "DragonHoard.h"
#include "SmallGold.h"
#include "Human.h"
#include "Dwarf.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orcs.h"
#include "Merchant.h"
#include "MerchantHoard.h"

std::string colorText(const std::string& text, const std::string& colorCode) {
    return "\033[" + colorCode + "m" + text + "\033[0m";
}


Floor::Floor() : map(), stairPos{ -1, -1 }, player{ nullptr } {
    map.reserve(numRows);
    for (int i = 0; i < numRows; ++i) {
        std::vector<Cell> row;
        row.reserve(numCols);
        for (int j = 0; j < numCols; ++j) {
            row.emplace_back('.', i, j, true);
        }
        map.push_back(row);
    }
}


void Floor::floor_init(PlayerCharacter* pc, const std::string& filename) {
    // Do not clear the map, just the objects on it.
    enemies.clear();
    potions.clear();
    goldsPiles.clear();

    std::ifstream file{ filename };
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < numRows) {
        for (size_t col = 0; col < line.length() && col < numCols; ++col) {
            char symbol = line[col];
            // Overwrite the existing cells instead of clearing and pushing back
            map[row][col].setSymbol(symbol);
            map[row][col].setIsPassable(symbol == '.' || symbol == '+' || symbol == '#');
        }
        row++;
    }

    std::vector<Position> availableFloorCells;
    // Safely iterate over the full, unmodified map dimensions
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (map[i][j].getBaseSymbol() == '.') {
                availableFloorCells.push_back(Position(i, j));
            }
        }
    }

    // shuffle the available floor cells
    std::shuffle(availableFloorCells.begin(), availableFloorCells.end(), std::mt19937{ std::random_device{}() });
    // place the player character at the first available floor cell



    std::vector<Position> chamberA, chamberB, chamberC, chamberD, chamberE;

    // Fill chamberA
    for (int row = 3; row <= 7; ++row) {
        for (int col = 3; col <= 29; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberA.push_back(Position(row, col));
            }
        }
    }
    // Fill chamberB
    for (int row = 3; row <= 7; ++row) {
        for (int col = 39; col <= 62; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberB.push_back(Position(row, col));
            }
        }
    }
    for (int row = 5; row <= 7; ++row) {
        for (int col = 62; col <= 70; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberB.push_back(Position(row, col));
            }
        }
    }
    for (int row = 6; row <= 7; ++row) {
        for (int col = 70; col <= 73; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberB.push_back(Position(row, col));
            }
        }
    }
    for (int row = 7; row <= 13; ++row) {
        for (int col = 61; col <= 76; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberB.push_back(Position(row, col));
            }
        }
    }
    // Fill chamberC
    for (int row = 10; row <= 13; ++row) {
        for (int col = 38; col <= 51; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberC.push_back(Position(row, col));
            }
        }
    }
    // Fill chamberD
    for (int row = 15; row <= 22; ++row) {
        for (int col = 4; col <= 25; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberD.push_back(Position(row, col));
            }
        }
    }
    // Fill chamberE
    for (int row = 16; row <= 19; ++row) {
        for (int col = 65; col <= 76; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberE.push_back(Position(row, col));
            }
        }
    }
    for (int row = 19; row <= 22; ++row) {
        for (int col = 37; col <= 76; ++col) {
            if (map[row][col].getBaseSymbol() == '.') {
                chamberE.push_back(Position(row, col));
            }
        }
    }

    std::vector<std::vector<Position>> chambers = {chamberA, chamberB, chamberC, chamberD, chamberE};

    // Randomly select a chamber for the player
    int playerChamberIdx = rand() % chambers.size();
    Position playerPos = chambers[playerChamberIdx][rand() % chambers[playerChamberIdx].size()];

    // Place player
    pc->setPosition(playerPos);
    map[playerPos.row][playerPos.col].placeCharacter(pc);
    player = pc;

    // Randomly select a different chamber for the stairway
    int stairChamberIdx;
    do {
        stairChamberIdx = rand() % chambers.size();
    } while (stairChamberIdx == playerChamberIdx);

    Position stair_position = chambers[stairChamberIdx][rand() % chambers[stairChamberIdx].size()];
    stairPos = stair_position;

    // Place stairway
    map[stair_position.row][stair_position.col].setSymbol('\\');

    // clear the availableFloorCells
    availableFloorCells.clear();
    // re-collect available cells
    for (int a = 0; a < numRows; a++) {
        for (int b = 0; b < numCols; b++) {
            // Only add cells that are floor, have no gold, no enemy, no player, no stairway, etc.
            if (map[a][b].getSymbol() == '.') {
                availableFloorCells.push_back(Position(a, b));
            }
        }
    }
    // shuffle the new availableFloorCells
    std::shuffle(availableFloorCells.begin(), availableFloorCells.end(), std::mt19937{ std::random_device{}() });
    // use the updated availableFloorCells for generation of the rest of objects





    // place 10 potions using index 2 - 11
    for (int i = 2; i < 12; i++) {
        int randomNum = rand() % 6;
        std::unique_ptr<Potion> potionPtr;
        if (randomNum == 0) {
            potionPtr = std::make_unique<RestoreHealth>();
        }
        else if (randomNum == 1) {
            potionPtr = std::make_unique<BoostAtk>();
        }
        else if (randomNum == 2) {
            potionPtr = std::make_unique<BoostDef>();
        }
        else if (randomNum == 3) {
            potionPtr = std::make_unique<PoisonHealth>();
        }
        else if (randomNum == 4) {
            potionPtr = std::make_unique<WoundAtk>();
        }
        else {
            potionPtr = std::make_unique<WoundDef>();
        }
        // place the potion in the map and store in potions container
        map[availableFloorCells[i].row][availableFloorCells[i].col].placePotion(potionPtr.get());
        potions.push_back(std::move(potionPtr));
    }


    // generate dragon hoard together with a dragon with probability 1/8
    int dragonHoardCount = 0;
    for (int idx = 12; idx < 22; idx++) {
        int randomNum_gold = rand() % 8;
        std::unique_ptr<DragonHoard> dragonHoardPtr;
        if (randomNum_gold == 0) {
            dragonHoardPtr = std::make_unique<DragonHoard>(availableFloorCells[idx]);    // generate Dragon Hoard
            dragonHoardCount++;
            // obtain the position of DragonHoard
            Position DragonHoardPos = availableFloorCells[idx];
            // collect available dragon spots
            std::vector<Position> dragonSpots;
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if (r == 0 && c == 0) continue;
                    int new_r = DragonHoardPos.row + r;
                    int new_c = DragonHoardPos.col + c;
                    if (new_r >= 0 && new_r < numRows && new_c >= 0 && new_c < numCols &&
                        map[new_r][new_c].getSymbol() == '.') {
                        dragonSpots.push_back(Position(new_r, new_c));
                    }
                }
            }

            // if there are available spots for dragon
            if (dragonSpots.size() != 0) {
                int randomNum_dragon = rand() % dragonSpots.size();
                Position dragonPos = dragonSpots[randomNum_dragon]; // randomly pick a positon from dragonSpots
                std::unique_ptr<Dragon> dragon = std::make_unique<Dragon>(dragonPos, dragonHoardPtr.get()); // create a dragon
                map[dragonPos.row][dragonPos.col].placeEnemy(dragon.get()); // place dragon on map
                enemies.push_back(std::move(dragon));   // add dragon to enemies
            }
            // place the dragon hoard in the map and store in goldPiles
            map[availableFloorCells[idx].row][availableFloorCells[idx].col].placeGold(dragonHoardPtr.get());
            goldsPiles.push_back(std::move(dragonHoardPtr));
        }
    }

    // clear the availableFloorCells
    availableFloorCells.clear();
    // re-collect available cells
    for (int a = 0; a < numRows; a++) {
        for (int b = 0; b < numCols; b++) {
            // Only add cells that are floor, have no gold, no enemy, no player, no stairway, etc.
            if (map[a][b].getSymbol() == '.') {
                availableFloorCells.push_back(Position(a, b));
            }
        }
    }
    // shuffle the new availableFloorCells
    std::shuffle(availableFloorCells.begin(), availableFloorCells.end(), std::mt19937{ std::random_device{}() });
    // use the updated availableFloorCells for generation of the rest of objects

    // place 10 - dragonHoardCount piles of gold using index 0 - 10-dragonHoardNum
    for (int j = 0; j < 10 - dragonHoardCount; j++) {
        int randomNum_gold = rand() % 7;
        std::unique_ptr<Gold> goldPtr;
        if (randomNum_gold < 5) {
            goldPtr = std::make_unique<NormalGold>();   // generate NormalGold
        } else {
            goldPtr = std::make_unique<SmallGold>();    // genereta small gold
        }
        // place the gold in the map and store in goldPiles
        map[availableFloorCells[j].row][availableFloorCells[j].col].placeGold(goldPtr.get());
        goldsPiles.push_back(std::move(goldPtr));
    }

    // place 20 enemies using index 11 - 30
    for (int r = 11; r < 30; r++) {
        int randomNum_enemy = rand() % 18;
        std::unique_ptr<Enemy> enemyPtr;
        Position enemyPos = availableFloorCells[r];
        if (randomNum_enemy < 4) {
            enemyPtr = std::make_unique<Human>(enemyPos);
        }
        else if (randomNum_enemy < 7) {
            enemyPtr = std::make_unique<Dwarf>(enemyPos);
        }
        else if (randomNum_enemy < 12) {
            enemyPtr = std::make_unique<Halfling>(enemyPos);
        }
        else if (randomNum_enemy < 14) {
            enemyPtr = std::make_unique<Elf>(enemyPos);
        }
        else if (randomNum_enemy < 16) {
            enemyPtr = std::make_unique<Orcs>(enemyPos);
        }
        else {
            enemyPtr = std::make_unique<Merchant>(enemyPos, std::make_unique<MerchantHoard>());
        }
        // place the enemy in the map and store in enemies
        map[enemyPos.row][enemyPos.col].placeEnemy(enemyPtr.get());
        enemies.push_back(std::move(enemyPtr));
    }
}

void Floor::printMap(PlayerCharacter* pc) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // Check to prevent out-of-bounds access on map rows
            if (i < map.size() && j < map[i].size()) {
                if (map[i][j].getSymbol() == '@') {
                    std::cout << colorText(std::string(1, map[i][j].getSymbol()), "34");
                } else if (map[i][j].getSymbol() == 'H' ||
                           map[i][j].getSymbol() == 'W' ||
                           map[i][j].getSymbol() == 'E' ||
                           map[i][j].getSymbol() == 'O' ||
                           map[i][j].getSymbol() == 'M' ||
                           map[i][j].getSymbol() == 'D' ||
                           map[i][j].getSymbol() == 'L') {
                    std::cout << colorText(std::string(1, map[i][j].getSymbol()), "31"); // enemy color
                } else if (map[i][j].getSymbol() == 'G') {
                    std::cout << colorText(std::string(1, map[i][j].getSymbol()), "33"); // gold color
                } else if (map[i][j].getSymbol() == 'P') {
                    std::cout << colorText(std::string(1, map[i][j].getSymbol()), "32"); // potion color
                } else {
                    std::cout << map[i][j].getSymbol();
                }
            }
        }
        std::cout << std::endl;
    }
}

const std::vector<std::unique_ptr<Enemy>>& Floor::getEnemies() const {
    return enemies;
}
const std::vector<std::unique_ptr<Potion>>& Floor::getPotions() const {
    return potions;
}
const std::vector<std::unique_ptr<Gold>>& Floor::getGoldPiles() const {
    return goldsPiles;
}

// 
Position Floor::movePlayer(Position oldPos, Direction dir, bool& goldCollected) {
    int newRow = oldPos.row;
    int newCol = oldPos.col;

    if (dir == Direction::N) newRow--;
    else if (dir == Direction::S) newRow++;
    else if (dir == Direction::E) newCol++;
    else if (dir == Direction::W) newCol--;
    else if (dir == Direction::NE) { newRow--; newCol++; }
    else if (dir == Direction::NW) { newRow--; newCol--; }
    else if (dir == Direction::SE) { newRow++; newCol++; }
    else if (dir == Direction::SW) { newRow++; newCol--; }

    // if new position is within the game board and not the boundary of game board, 
    // not occupied by Dragon or Merchant -> place pc on the map and return the updated position
    if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && 
        map[newRow][newCol].getBaseSymbol() != '|' && map[newRow][newCol].getBaseSymbol() != '-' && 
        map[newRow][newCol].getBaseSymbol() != ' ' && 
        (map[newRow][newCol].getEnemy() == nullptr || (map[newRow][newCol].getEnemy()->getSymbol() != 'D' && map[newRow][newCol].getEnemy()->getSymbol() != 'M'))) {
        
        // Check for gold collection before moving
        Cell& targetCell = map[newRow][newCol];
        Gold* gold = targetCell.getGold();
        goldCollected = false;
        if (gold && gold->getIsPickable()) {
            // Add gold to player
            player->addGold(gold->getValue());
            goldCollected = true;
            // Remove gold from cell and floor
            targetCell.removeGold();
            // Remove from goldsPiles vector
            for (int i = 0; i < goldsPiles.size(); i++) {
                if (goldsPiles[i].get() == gold) {
                    goldsPiles.erase(goldsPiles.begin() + i);
                    break;      // stop searching
                }
            }
        }
        // remove pc from old position, place pc to new position
        map[oldPos.row][oldPos.col].removeCharacter();
        map[newRow][newCol].placeCharacter(player);
        return Position{newRow, newCol};
    }
    // movement failed, return original position
    return oldPos;
}

// return the cell at (row, col)
Cell& Floor::getTargetCell(int row, int col) {
    return map[row][col];
}

// return the positon of stairway
Position Floor::getStairPos() const {
    return stairPos;
}

void Floor::moveRandom(Enemy* enemy) {
    if (enemy == nullptr || !enemy->getMoveStatus()) { // if there is no enemy or enemy cannot move
        return;
    }
    Position currPos = enemy->getPosition(); // store the current position of enemy
    std::vector<Position> validlandingPos;  // stores the 8 surrounding positions around enemy

    // loop through the surrounding 8 positions around the enemy
    for (int row_diff = -1; row_diff <= 1; row_diff++) {
        for (int col_diff = -1; col_diff <= 1; col_diff++) {
            if (row_diff == 0 && col_diff == 0) continue; // skip enemy's position

            Position newPos = { currPos.row + row_diff, currPos.col + col_diff };

            if (newPos.row >= 0 && newPos.row < numRows &&
                newPos.col >= 0 && newPos.col < numCols &&  // if new position is within the board
                map[newPos.row][newPos.col].getBaseSymbol() == '.' && // new position is empty
                map[newPos.row][newPos.col].getEnemy() == nullptr &&    // no enemy at new position
                map[newPos.row][newPos.col].getSymbol() != '@') {   // pc is not at new position
                validlandingPos.emplace_back(newPos);   // store this position into validlandingPos
            }
        }
    }
    
    // random generation logic
    if (!validlandingPos.empty()) { // if there is valid landing position
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, validlandingPos.size() - 1);

        int randomIndex = distrib(gen);
        Position newPos = validlandingPos[randomIndex];

        map[currPos.row][currPos.col].removeEnemy();    // remove enemy from original position
        enemy->setPosition(newPos);     // set enemy to new position - update enemy's field
        map[newPos.row][newPos.col].placeEnemy(enemy);      // place enemy to new position on map
    }
} 

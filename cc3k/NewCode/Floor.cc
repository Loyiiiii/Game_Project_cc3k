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

std::string raceToString(Race race) {
    switch (race) {
        case Race::SHADE: return "Shade";
        case Race::DROW: return "Drow";
        case Race::VAMPIRE: return "Vampire";
        case Race::TROLL: return "Troll";
        case Race::GOBLIN: return "Goblin";
        default: return "Unknown";
    }
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

void printInfo(PlayerCharacter* pc) {
    std::cout << "Race: " << raceToString(pc->getRace()) << " Gold: " << pc->getGold() << " Floor: " << std::endl;
    std::cout << "HP: " << pc->getHP() << std::endl;
    std::cout << "Atk: " << pc->getAtk() << std::endl;
    std::cout << "Def: " << pc->getDef() << std::endl;
    std::cout << "Action: " << std::endl;
}

void Floor::floor_init(PlayerCharacter* pc, const std::string& filename) {
    // Do not clear the map, just the objects on it.
    enemies.clear();
    potions.clear();
    goldsPiles.clear();

    std::ifstream file{ "../" + filename };
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < numRows) {
        for (int col = 0; col < line.length() && col < numCols; ++col) {
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
    std::shuffle(availableFloorCells.begin(), availableFloorCells.end(), std::mt19937{ std::random_device{}() });

    Position playerPos = availableFloorCells[0];
    pc->setPosition(playerPos);
    map[playerPos.row][playerPos.col].placeCharacter(pc);
    player = pc;

    stairPos = availableFloorCells[1];
    map[stairPos.row][stairPos.col].setSymbol('\\');

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
        map[availableFloorCells[i].row][availableFloorCells[i].col].placePotion(potionPtr.get());
        potions.push_back(std::move(potionPtr));
    }

    for (int j = 12; j < 22; j++) {
        int randomNum_gold = rand() % 8;
        std::unique_ptr<Gold> goldPtr;
        if (randomNum_gold < 5) {
            goldPtr = std::make_unique<NormalGold>();
        }
        else if (randomNum_gold == 5) {
            goldPtr = std::make_unique<DragonHoard>(availableFloorCells[j]);
        }
        else {
            goldPtr = std::make_unique<SmallGold>();
        }
        map[availableFloorCells[j].row][availableFloorCells[j].col].placeGold(goldPtr.get());
        goldsPiles.push_back(std::move(goldPtr));
    }

    for (int r = 22; r < 42; r++) {
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
        map[enemyPos.row][enemyPos.col].placeEnemy(enemyPtr.get());
        enemies.push_back(std::move(enemyPtr));
    }
}

void Floor::printMap(PlayerCharacter* pc) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // Check to prevent out-of-bounds access on map rows
            if (i < map.size() && j < map[i].size()) {
                if (map[i][j].getSymbol() == "@") {
                    std::cout << colorText(map[i][j].getSymbol(), "34");
                } else if (map[i][j].getSymbol() == "H" ||
                           map[i][j].getSymbol() == "W" ||
                           map[i][j].getSymbol() == "E" ||
                           map[i][j].getSymbol() == "O" ||
                           map[i][j].getSymbol() == "M" ||
                           map[i][j].getSymbol() == "D" ||
                           map[i][j].getSymbol() == "L") {
                    std::cout << colorText(map[i][j].getSymbol(), "31");
                } else if (map[i][j].getSymbol() == "G") {
                    std::cout << colorText(map[i][j].getSymbol(), "33");
                } else if (map[i][j].getSymbol() == "P") {
                    std::cout << colorText(map[i][j].getSymbol(), "32");
                } else {
                    std::cout << map[i][j].getSymbol();
                }
            }
        }
        std::cout << std::endl;
    }
    printInfo(pc);
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

Position Floor::movePlayer(Position oldPos, Direction dir) {
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

    if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && map[newRow][newCol].getBaseSymbol() != '|' && map[newRow][newCol].getBaseSymbol() != '-') {
        map[oldPos.row][oldPos.col].removeCharacter();
        map[newRow][newCol].placeCharacter(player);
        return Position{ newRow, newCol };
    }
    return oldPos;
}

Cell& Floor::getTargetCell(int row, int col) {
    return map[row][col];
}

Position Floor::getStairPos() const {
    return stairPos;
}

void Floor::moveRandom(Enemy* enemy) {
    if (enemy == nullptr || !enemy->getMoveStatus()) {
        return;
    }
    Position currPos = enemy->getPosition();
    std::vector<Position> validlandingPos;

    for (int row_diff = -1; row_diff <= 1; row_diff++) {
        for (int col_diff = -1; col_diff <= 1; col_diff++) {
            if (row_diff == 0 && col_diff == 0) continue;

            Position newPos = { currPos.row + row_diff, currPos.col + col_diff };

            if (newPos.row >= 0 && newPos.row < numRows &&
                newPos.col >= 0 && newPos.col < numCols &&
                map[newPos.row][newPos.col].getBaseSymbol() == '.' &&
                map[newPos.row][newPos.col].getEnemy() == nullptr &&
                map[newPos.row][newPos.col].getSymbol() != '@') {
                validlandingPos.emplace_back(newPos);
            }
        }
    }

    if (!validlandingPos.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, validlandingPos.size() - 1);

        int randomIndex = distrib(gen);
        Position newPos = validlandingPos[randomIndex];

        map[currPos.row][currPos.col].removeEnemy();
        enemy->setPosition(newPos);
        map[newPos.row][newPos.col].placeEnemy(enemy);
    }
} 
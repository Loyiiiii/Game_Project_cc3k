module floor;

Floor::Floor(): map{rows, std::vector<Cell>(col, Cell{'.', 0, 0})} {}

// helper: printInfo(PlayerCharacter *pc);
void printInfo(PlayerCharacter *pc) {
    Race race = pc->getRace();
    int hp = pc->getHealth();
    int atk = pc->getAtk();
    int def = pc->getDef();
    std::cout << "Race: " << race << " " << "Gold: " << pc->getGoldATM() << "" << "Floor: " <<  endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std:: endl;
    std::cout << "Def: " << def << std::endl;
    std::cout << "Action: " << endl;
}


void Floor::floor_init(PlayerCharacter *pc, const std::string &filename):  {
    // clear the original map
    map.clear();

    std::ifstream file{filename};
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < numRows) {
        for (int col = 0; col < numCols; col++) {
            if (line[col] == '|' || line[col] == '-') {
                map[row][col] = Cell{line[col], row, col, false}; // walls are not passable
            } else {
                map[row][col] = Cell{line[col], row, col, true}; // floor cells are passable
            }
        }
        row++;
    }

    // Place player, enemies, potions, gold as needed
    // iterate through the map and collect the positions of all walkable floor cells
    std::vector<Position> availableFloorCells;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (map[i][j].getBaseSymbol() == '.') {
                availableFloorCells.push_back(Position(i, j));
            }
        }
    }
    // shuffle the available floor cells
    std::shuffle(availableFloorCells.begin(), availableFloorCells.end(), std::mt19937{std::random_device{}()});
    // place the player character at the first available floor cell
    Position playerPos = availableFloorCells[0];
    pc.setPosition(playerPos);
    map[playerPos.row][playerPos.col].placeCharacter(pc);


    // place the stairway at the second available floor cell
    map[availableFloorCells[1].row][availableFloorCells[1].col].setSymbol('\\');

    // place 10 potions using index 2 - 11
    for (int i = 2; i < 12; i++) {
        int randomNum = rand() % 6;
        std::unique_ptr<Item> potionPtr;
        // randomly choose a potion type
        // 0: HEALTH_RESTORE, 1: ATK_BOOST, 2: DEF_BOOST, 3. POISON_HEALTH, 4. WOUND_ATK, 5. WOUND_DEF
        if (randomNum == 0) {
            potionPtr = std::make_unique<HealthRestore>();
        } else if (randomNum == 1) {
            potionPtr = std::make_unique<BoostAtk>();
        } else if (randomNum == 2) {
            potionPtr = std::make_unique<BoostDef>();
        } else if (randomNum == 3) {
            potionPtr = std::make_unique<PoisonHealth>();
        } else if (randomNum == 4) {
            potionPtr = std::make_unique<WoundAtk>();
        } else {
            potionPtr = std::make_unique<WoundDef>();
        }

        // place the potion in the map and store in potions
        map[availableFloorCells[i].row][availableFloorCells[i].col].placeItem(potionPtr.get());
        potions.push_back(std::move(potionPtr));
    }

    // place 10 piles of gold using index 12 - 21
    for (int j = 12; j < 22; j++) {
        int randomNum_gold = rand() % 8; // 0-7
        std::unique_ptr<Item> goldPtr;
        // randomly choose a gold type
        // 0 - 4: normal gold, 5: dragon hoard, 6 - 7: small gold
        if (randomNum_gold < 5) {
            goldPtr = std::make_unique<NormalGold>();
        } else if (randomNum_gold == 5) {
            goldPtr = std::make_unique<DragonHoard>();
        } else {
            goldPtr = std::make_unique<SmallGold>();
        }

        // place the gold in the map and store in goldPiles
        map[availableFloorCells[j].row][availableFloorCells[j].col].placeItem(goldPtr.get());
        goldsPiles.push_back(std::move(goldPtr));
    }

    // place 20 enemies using index 22 - 41
    for (int r = 22; r < 42; r++) {
        int randomNum_enemy = rand() % 18; // 0-17
        std::unique_ptr<Enemy> enemyPtr;
        Position enemyPos = availableFloorCells[r];
        // randomly choose an enemy type
        // 0 - 3: Human, 4 - 6: Dwarf, 7 - 11: halfling, 12 - 13: Elf, 14 - 15: Orc, 16 - 17: Merchant
        if (randomNum_enemy < 4) {
            enemyPtr = std::make_unique<Human>(enemyPos);
        } else if (3 < randomNum_enemy < 7) {
            enemyPtr = std::make_unique<Dwarf>(enemyPos);
        } else if (6 < randomNum_enemy < 12) {
            enemyPtr = std::make_unique<Halfling>(enemyPos);
        } else if (11 < randomNum_enemy < 14) {
            enemyPtr = std::make_unique<Elf>(enemyPos);
        } else if (13 < randomNum_enemy < 16) {
            enemyPtr = std::make_unique<Orc>(enemyPos);
        } else {
            enemyPtr = std::make_unique<Merchant>(enemyPos);
        }
        // place the enemy in the map and store in enemies
        map[enemyPos.row][enemyPos.col].placeEnemy(enemyPtr.get());
        enemies.push_back(std::move(enemyPtr));
    }
    // assign pc to the player pointer
    player = pc;

    std::cout << std::endl;
}


void Floor::printMap(PlayerCharacter *pc) {
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            std::cout << map[i][j].getSymbol();
        }
        std::cout << std::endl;
    }
    printInfo(pc); // print info below the map
}


// Accessor
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
    int oldRow = oldPos.row;
    int oldCol = oldPos.col;
    int newRow, newCol;
    if (dir == Direction::N) {
        newRow = oldRow - 1;
        newCol = oldCol;
    } else if (dir == Direction::S) {
        newRow = oldRow + 1;
        newCol = oldCol;
    } else if (dir == Direction::E) {
        newRow = oldRow;
        newCol = oldCol + 1;
    } else if (dir == Direction::W) {
        newRow = oldRow;
        newCol = oldCol - 1;
    } else if (dir == Direction::NE) {
        newRow = oldRow - 1;
        newCol = oldCol + 1;
    } else if (dir == Direction::NW) {
        newRow = oldRow - 1;
        newCol = oldCol - 1;
    } else if (dir == Direction::SE) {
        newRow = oldRow + 1;
        newCol = oldCol + 1;
    } else {
        newRow = oldRow + 1;
        newCol = oldCol - 1;
    }
    // check if the new position is within bounds and passable
    if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) {
        return Position{oldRow, oldCol}; // out of bounds, return old position
    } else if (!map[newRow][newCol].isPassable()) {
        return Position{oldRow, oldCol}; // not passable, return old position
    } else {
        // move the player character to the new position
        map[oldRow][oldCol].removeCharacter();
        map[newRow][newCol].placeCharacter(player);
        return Position{newRow, newCol}; // return the new position
    }
}

Cell& Floor::getTargetCell(int row, int col) {
    return map[row][col];
}

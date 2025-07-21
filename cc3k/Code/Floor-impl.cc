module floor;

Floor::Floor(int rows, int cols)
    : numRows{rows}, num{cols}, map{rows, std::vector<Cell>(col, Cell{'.', 0, 0})} {}

// helper: printInfo(PlayerCharacter *pc);
void printInfo(PlayerCharacter *pc) {
    Race race = pc->getRace();
    int hp = pc->getHealth();
    int atk = pc->getAtk();
    int def = pc->getDef();
    std::cout << "Race: " << race << " " << "Gold: " << endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std:: endl;
    std::cout << "Def: " << def << std::endl;
    std::cout << "Action: " << endl;
}


void Floor::floor_init(PlayerCharacter *pc, const std::string &filename):  {
    // clear the original map
    map.clear()

    std::ifstream file{filename};
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < numRows) {
        for (int col = 0; col < numCols; col++) {
            map[row][col] = Cell{line[col], row, col};
        }
        row++;
    }
    // Place player, enemies, potions, gold as needed
    
    std::cout << std::endl;
    printInfo(pc); // print info below the map
}

void Floor::loadMap()

void Floor::printMap() {
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            std::cout << map[i][j].getSymbol();
        }
        std::cout << std::endl;
    }
}

void Floor::movePlayer(int oldRow, int oldCol, int newRow, int newCol) {
    map[oldRow][oldCol].player = nullptr; // remove player from old cell
    map[newRow][newCol].player = player; // place player in new cell
    player->setPos(Position(newRow, newCol)); // update player's position
    map[newRow][newCol].setSymbol(player->getSymbol()); // update cell symbol
}

module Floor;

// copy emptyfloor.txt into the folder
// use input file stream
// move each item into the map

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


void Floor::floor_init(PlayerCharacter *pc):  {
    // clear the original map
    map.clear()

    std::ifstream file{"emptyfloor.txt"};
    std::string line;
    int lineNum;
    while (std::getline(file, line)) {
        // create a vector of Cell
        std::vector<Cell> row;
        lineNum = map.size();
        for (int i = 0; i < 79; i++) {
            char currSymbol = char(line[i]); // get the current char
            Cell cell{currSymbol, lineNum, i}
            cell.setIsPassable(currSymbol == '.');
        }
        map.push_back(std::move(row));
    }
    
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

export module Floor;

import <iostream>;
import <vector>;
import <string>;
import Cell;
import Global_Constants;

export class Floor {
    int maxRow = 30;
    int maxCol = 79;
    std::vector<std::vector<Cell>> map;

public:
    void floor_init();
    void loadMap();
    void printMap();

};

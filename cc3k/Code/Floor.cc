export module floor;

import <iostream>;
import <vector>;
import <string>;
import <memory>;
import <algorithm>;
import <random>;
import <cstdlib>;

import Cell;
import Enemy;
import Potion;
import Gold;
// import Position;
import PlayerCharacter;
import Global_Constants;

export class Floor {
    int numRows = 30;
    int numCols = 79;
    std::vector<std::vector<Cell>> map;
    // container for Enemy, Potions, Gold
    /*
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Potion>> potions;
    std::vector<std::unique_ptr<Gold>> goldsPiles;
    */

    PlayerCharacter *player = nullptr; // to know where the player is on the floor

public:
    Floor();

    void floor_init(PlayerCharacter *pc, const std::string &filename); // Pass player pointer for initialization
    void printMap();

    /*
    // add/remove methods
    void addEnemy(std::unique_ptr<Enemy> e);
    void addPotion(std::unique_ptr<Potion> p);
    void addGold(std::unique_ptr<Gold> g);
    */

    // Accessor
    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
    const std::vector<std::unique_ptr<Potion>>& getPotions() const;
    const std::vector<std::unique_ptr<Gold>>& getGoldPiles() const;

    // move the player character
    Position movePlayer(Position oldPos, Direction dir);
};

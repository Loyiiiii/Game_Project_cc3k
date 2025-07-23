export module GamePlay;
import <iostream>;
import <string>;
import <vector>;
import PlayerCharacter;
import floor;
import Global_Constants;
import position;
import floor_level;
import potion;

using namespace std;

export class Gameplay {
public:
    Gameplay();

    void setPlayerRace(Race race);
    void gameInit();
    GameResult mainLoop();

private:
    int currentFloorNumber;
    bool enemyFrozen;

    unique_ptr<PlayerCharacter> player;
    unique_ptr<Floor> currentFloor;

    void displayGameState();
    bool parseAndExecuteCommand(const string &cmd);
    void enemyTurn();
    bool checkEndConditions();

    bool handleMove(Direction dir);
    bool handleAttack(Direction dir);
    bool handleUsePotion(Direction dir);

    Direction parseDirection(const string &dirStr);
    void printHelp();

    Direction parseDirection(const string& dirStr);
    Position getTargetPosition(Position pos, Direction dir);
};
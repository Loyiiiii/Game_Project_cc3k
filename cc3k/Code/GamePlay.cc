/** export module GamePlay;
import <iostream>;
import <fstream>;
import <sstream>;
import <string>;
import <utility>;
import <compare>;
import <vector>;
import <algorithm>;
using namespace std;

class Gameplay {
    unique_ptr<PC> player;
    unique_ptr<Floor> floor;
    bool frozenEnemies = false;
    bool gameOver = false;
    int currentFloor = 1;

public:
    void startGame();
    void mainLoop();

private:
    void chooseRace();
    void generateFloor();
    void handleCommand(const string& cmd);
    void updateEnemies();
    void resolveDeaths();
    void checkVictoryOrDeath();
    void render();
};

//仍需和其他模块进行交互查看如何互相使用
**/

export module GamePlay;
import <iostream>;
import <string>;
import <vector>;
import GamePlay;
import PlayerCharacter;
import Direction;
import Floor;
import MapPrinter;
import Global_Constants;

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
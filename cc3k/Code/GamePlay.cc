export module GamePlay;
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


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

    GameResult mainLoop();

private:
    int currentFloorNumber;
    bool enemyFrozen;

    unique_ptr<PlayerCharacter> player;
    unique_ptr<Floor> currentFloor;

    void setPlayerRace(Race race);
    Direction parseDirection(const string& dirStr);
    Position getTargetPosition(Position pos, Direction dir);
};
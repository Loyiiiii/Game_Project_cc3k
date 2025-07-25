#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <string>
#include <memory>
#include "PlayerCharacter.h"
#include "FloorLevel.h"
#include "Global_Constants.h"
#include "GameInit.h"

class GamePlay {
    bool enemyFrozen;

    std::unique_ptr<PlayerCharacter> player;
    std::unique_ptr<FloorLevel> allFloorLevel;

    Direction parseDirection(const std::string& dirStr);
    Position getTargetPosition(Position pos, Direction dir);

public:
    GamePlay();
    ~GamePlay();

    void setPlayerRace(Race race);
    void gameInit();
    ResultCombo mainLoop();
};

#endif 

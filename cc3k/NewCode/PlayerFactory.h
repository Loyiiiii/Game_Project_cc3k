#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include <memory>
#include "PlayerCharacter.h"
#include "Global_Constants.h"
#include "Position.h"

class PlayerFactory {
public:
    std::unique_ptr<PlayerCharacter> createPlayer(Race race, Position start_pos);
    Race selectRace();
};

#endif 
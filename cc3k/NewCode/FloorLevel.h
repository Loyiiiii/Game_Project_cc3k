#ifndef FLOOR_LEVEL_H
#define FLOOR_LEVEL_H

#include <vector>
#include <memory>
#include <string>

#include "Floor.h"
#include "PlayerCharacter.h"

class FloorLevel {
    std::vector<std::unique_ptr<Floor>> floors;
    int currentFloorNum;

public:
    FloorLevel(int numFloors = 5);

    Floor* getCurrentFloor();
    int getCurrentFloorNum() const;
    void goToNextFloor(PlayerCharacter* pc, const std::string& filename);
};

#endif 
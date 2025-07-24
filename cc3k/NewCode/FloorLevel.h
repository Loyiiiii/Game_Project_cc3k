#ifndef FLOOR_LEVEL_H
#define FLOOR_LEVEL_H

#include <vector>
#include <memory>
#include <string>

#include "Floor.h"
#include "PlayerCharacter.h"

class FloorLevel {
    std::vector<std::unique_ptr<Floor>> floors;     // store 5 Floor object
    int currentFloorNum;    // represents floor number pc currently at

public:
    FloorLevel(int numFloors = 5);

    Floor* getCurrentFloor();   // return a Floor pointer that points to current floor
    int getCurrentFloorNum() const;     // getter - return current floor number
    // let pc enter next floor
    void goToNextFloor(PlayerCharacter* pc, const std::string& filename);
};

#endif 

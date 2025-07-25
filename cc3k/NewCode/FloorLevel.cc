#include "FloorLevel.h"

FloorLevel::FloorLevel(int numFloors) : currentFloorNum{1} {
    for (int i = 0; i < numFloors; i++) {   // created 5 Floor object an append them to floors
        floors.push_back(std::make_unique<Floor>());
    }
}

Floor* FloorLevel::getCurrentFloor() { // return current floor pointer
    return floors[currentFloorNum - 1].get();
}

int FloorLevel::getCurrentFloorNum() const { // return current floor number
    return currentFloorNum;
}

void FloorLevel::goToNextFloor(PlayerCharacter* pc, const std::string& filename) {
    if (currentFloorNum < floors.size()) { // if player has not reached the highest level
        // clear the temp potion effects before transitioning to new floor
        pc->clearTempPotionEffects();
        currentFloorNum++;  // increment floor number
        floors[currentFloorNum - 1]->floor_init(pc, filename);  // initialize Floor at new level
    }
} 

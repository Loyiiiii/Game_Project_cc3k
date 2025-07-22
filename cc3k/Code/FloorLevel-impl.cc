module floor_level;

FloorLevel::FloorLevel(int numFloors): currentFloorNum{1} {
    for (int i = 0; i < numFloors; i++) {
        floors.push_back(std::make_unique<Floor>());
    }
}

Floor* FloorLevel::getCurrentFloor() {
    return floors[currentFloorNum - 1].get();
}

int FloorLevel::getCurrentFloorNum() const {
    return currentFloorNum;
}

void FloorLevel::goToNextFloor(PlayerCharacter *pc, const std::string &filename) {
    if (currentFloorNum < floors.size()) {
        currentFloorNum++;
        floors[currentFloorNum - 1]->floor_init(pc, filename);
    } else {
        // end of game, handle win condition
    }
}

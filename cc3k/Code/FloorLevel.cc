export module floor_level;

import PlayerCharacter;
import floor;
import <vector>;
import <memory>;

export class FloorLevel {
    std::vector<std::unique_ptr<Floor>> floors; // vector to hold multiple floors
    int currentFloorNum; // index of the current floor

public:
    FloorLevel(int numFloors = 5); // constructor to initialize floors

    Floor *getCurrentFloor();
    int getCurrentFloorNum() const;
    void goToNextFloor(PlayerCharacter *pc, const std::string &filename);
}

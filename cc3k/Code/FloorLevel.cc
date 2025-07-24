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

    Floor *getCurrentFloor();   // get the current floor object
    int getCurrentFloorNum() const;     // get the current floor number
    void goToNextFloor(PlayerCharacter *pc, const std::string &filename); // move to the next floor
};

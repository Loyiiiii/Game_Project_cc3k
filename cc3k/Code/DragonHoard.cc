export module dragon_hoard;

import gold;
import Position;
import Global_Constants;

export class DragonHoard : public Gold {
    Position pos;  
public:
    DragonHoard(Position pos); // Constructor takes position parameter
    Position getPosition() const;   // Getter for position
    // Dragon Hoard is initially unpickable, but can be made pickable later
};

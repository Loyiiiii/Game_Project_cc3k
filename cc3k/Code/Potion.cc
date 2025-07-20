export module potion;

import Global_Constants;

export class Potion : public Item {
    Potion_Type type;
    bool isTemporary; // whether the potion is temporary or permanent
    int magnitude; // the magnitude of the potion effect
    Position pos; // the position of the potion in the game world
    
public:

}

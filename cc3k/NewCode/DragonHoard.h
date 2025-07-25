#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include "Gold.h"
#include "Position.h"
#include "Global_Constants.h"

class DragonHoard : public Gold {
    Position pos;
public:
    DragonHoard(Position pos);
    Position getPosition() const;
};

#endif 

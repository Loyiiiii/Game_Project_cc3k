#include "DragonHoard.h"
#include "Position.h"

DragonHoard::DragonHoard(Position position) :
    Gold{ 6, false }, pos{ position } {}

Position DragonHoard::getPosition() const {
    return pos;
} 

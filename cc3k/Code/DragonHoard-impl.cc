module dragon_hoard;
import Position;

DragonHoard::DragonHoard(Position position): 
Gold{6, false}, pos{position} {}

Position DragonHoard::getPosition() const {
    return pos;
}

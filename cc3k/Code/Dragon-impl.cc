module Dragon;
import Enemy;
import PlayerCharacter;
import DragonHoard;
import Global_Constants;

Dragon::Dragon(Position pos, std::unique_ptr<DragonHoard> hoard):
// std::move is used to transfer ownership of the hoard pointer to the Dragon object. 
    Enemy{pos, 150, 20, 20, false, true, 'D'}, hoard{std::move(hoard)} {}

Dragon::~Dragon() {}


void Dragon::attack(PlayerCharacter& pc) {
    int damage = calculateDamage(this->Atk, pc.getDef());
    pc.takeDamage(damage);
}

void Dragon::dropGold(PlayerCharacter& pc) {
    hoard->setIsPickable(true); // dragon is dead, hoard is pickable. 
}

void Dragon::takeDamage(int dmg) {
    if (this->getHP() - dmg <= 0) {
        HP = 0;
    } else {
        HP -= dmg;
    }
}



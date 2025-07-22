export module dwarf;

import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Dwarf : public Enemy {
public:
    Dwarf(Position pos);

    void attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
}

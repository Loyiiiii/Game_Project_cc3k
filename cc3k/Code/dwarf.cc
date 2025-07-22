export module dwarf;

import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Dwarf : public Enemy {
public:
    Dwarf(Position pos);

    void attack(PlayerCharacter& pc) override;
    void dropGold(int goldAmount) override;
    void takeDamage(int damage) override;
    bool is_alive();
    int getAtk();
    int getDef();
}

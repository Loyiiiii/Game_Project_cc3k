export module dwarf;

import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Dwarf : public Enemy {
public:
    Dwarf(Position pos, int HP = 100, int Atk = 20, int Def = 30, bool movable = true);

    void attack(PlayerCharacter& pc) override;
    void dropGold() override;
    char getSymbol() override;
    void takeDamage(int damage) override;
    bool is_alive();
    int getAtk();
    int getDef();
}

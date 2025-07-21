export module elf;

import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Elf : public Enemy {
public:
    Elf(Position pos, int HP = 140, int Atk = 30, int Def = 10, bool movable = true);

    void attack(PlayerCharacter& pc) override;
    void dropGold() override;
    char getSymbol() override;
    void takeDamage(int damage) override;
    bool is_alive();
    int getAtk();
    int getDef();
}

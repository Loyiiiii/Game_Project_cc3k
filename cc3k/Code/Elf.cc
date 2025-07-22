export module elf;

import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Elf : public Enemy {
public:
    Elf(Position pos);

    void attack(PlayerCharacter& pc) override;
    void dropGold() override;
    void takeDamage(int damage) override;
}

export module halfling;

import Enemy;
import position;
import Global_Constants;

export class Halfling : public Enemy {
public:
    Halfling(Position pos);

    void attack(PlayerCharacter &pc) override;
    void dropGold(PlayerCharacter &pc) override;
    void takeDamage(int damage) override;
}
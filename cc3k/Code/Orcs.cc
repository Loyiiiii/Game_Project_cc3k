export module Orcs;
import Enemy;
import PlayerCharacter;
import Global_Constants;

export class Orcs: public Enemy {
    public:
        Orcs(Position pos);
        ~Orcs();
        void attack(PlayerCharacter& pc) override;
        void dropGold(PlayerCharacter& pc) override;
        void takeDamage(int damage) override;
};

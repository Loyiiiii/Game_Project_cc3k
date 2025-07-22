export module Dragon;
import Enemy;
import PlayerCharacter;
import Global_Constants;
import DragonHoard;

// Dragon: 150HP, 20ATK, 20DEF
// guards a treasure hoard. 

export class Dragon: public Enemy {
    std::unique_ptr<DragonHoard> hoard;
    public:
        Dragon(Position pos, std::unique_ptr<DragonHoard> hoard);
        ~Dragon();
        void attack(PlayerCharacter& pc) override;
        void dropGold(PlayerCharacter& pc) override;
        void takeDamage(int dmg) override;
}

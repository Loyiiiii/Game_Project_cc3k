export module Human;
import <vector>;
import <memory>;
import Enemy;
import PlayerCharacter;
import Global_Constants;
import NormalGold;


export class Human: public Enemy {
    private:
    std::vector<std::unique_ptr<NormalGold>> gold_carried;
    public:
        Human(Position pos);
        ~Human();
        void attack(PlayerCharacter& pc) override; // attack PlayerCharacter
        void dropGold() override;
        char getSymbol() override;
        void takeDamage(int damage) override; // receive damage from PlayerCharacter
};

export module Enemy;
import Gold;
import Global_Constants;
import PlayerCharacter;

export class Enemy {
    protected:
        int HP;
        int Atk;
        int Def;
        Position pos;
        bool movable;
    public:
        Enemy(Position pos, int HP, int Atk, int Def, bool movable);
        virtual ~Enemy();
        virtual void attack(PlayerCharacter& pc) = 0; // needs to know facing what character
        virtual void dropGold() = 0;
        virtual char getSymbol() = 0;
        bool is_alive();
};
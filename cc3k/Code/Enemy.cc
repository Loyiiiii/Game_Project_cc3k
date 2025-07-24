export module Enemy;
import gold;
import Global_Constants;
import position;

class PlayerCharacter;


export class Enemy {
    protected:
        Position pos;
        int HP;
        int Atk;
        int Def;
        bool movable;
        bool is_neutral;
        char symbol;
        // Combat utility method
        int calculateDamage(int attackAtk, int defenderDef);
    public:
        Enemy(Position pos, int HP, int Atk, int Def, bool movable, bool is_neutral, char symbol);
        virtual ~Enemy();
        char getSymbol() const;
        bool is_alive() const;
        bool isAdjacentTo(const Position& pc_pos) const;
        void setPosition(Position newPos); 
        
        // these Pure Virtual Functions are the interface for the Enemy class
        virtual void attack(PlayerCharacter& pc) = 0; // needs to know facing what character
        virtual void dropGold(PlayerCharacter& pc) = 0;
        virtual void takeDamage(int damage) = 0;

        // Getters:
        int getAtk() const;
        int getDef() const;
        int getHP() const;
        void setHP();       // ********************* add this
        bool getMoveStatus() const;
        Position getPosition() const; 
};

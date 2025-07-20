import PlayerCharacter;
import Global_Constants;

export module Goblin;

// Goblin: 110 HP, 15 Atk, 20 Def, steals 5 gold from every enemy slain.
export class Goblin: public PlayerCharacter{
    private:
        void StealGold();
    public:
        Goblin(Position pos);
};

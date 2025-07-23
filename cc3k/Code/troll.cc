import PlayerCharacter;
import Global_Constants;

export module Troll;

//  troll (120 HP, 25 Atk, 15 Def, regains 5 HP every turn; HP is capped at 120 HP)
export class Troll: public PlayerCharacter{
    protected:
        // this should be called by GamePlay::move()
        void gainHP();
    public:
        Troll();
};

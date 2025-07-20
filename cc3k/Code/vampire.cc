import PlayerCharacter;
import Global_Constants;

export module Vampire; 

// vampire: 50 HP, 25 ATK, 25 Def.
// no Max HP, and gains 5HP per successful attack. 
export class Vampire: public PlayerCharacter{
    private:
        void gainHP(); // gain 5HP per successful attack. 
    public:
        Vampire(Position pos);
        void attack() override;
};

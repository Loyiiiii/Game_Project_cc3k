import <iostream>;
import <string>;

export module PlayerCharacter;

export class PlayerCharacter {
    Position pos; // representing the position of the PC
    int health; // representing the HP
    int maxHealth; // representing the max HP
    int atk; // representing the attack power
    int def; // representing the defense power
    int goldATM; // representing the gold of the PC
    Race race; // representing the race of the PC (from Global_Constants)
    bool has_max_health; // representing if the PC has the max health - reserved for Vampire.

    // some additional things came to me: 
    protected:
        std::vector<Potion> PotionInUse; // representing the potions the PC is currently using
    
    
    public: 
        void drinkPotion(Potion p); // drinks a potion and gains its effects
        PlayerCharacter(Position pos, int health, int maxHealth, 
            int atk, int def, int goldATM, Race race, bool has_max_health = false); // default to false, unless Vampire
        virtual ~PlayerCharacter() = default; // Virtual destructor for proper inheritance
        // Getters
        Position getPos();
        int getHealth();
        int getMaxHealth();
        bool HasMaxHealth();
        int getAtk();
        int getDef();
        int getGoldATM();
        Race getRace();
        
        // Virtual methods that races can override
        virtual void attack();
        virtual void takeDamage(int damage);
};












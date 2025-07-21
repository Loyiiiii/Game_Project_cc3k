export module PlayerCharacter;
import <iostream>;
import <string>;
import Global_Constants;

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
        
        // Combat utility method
        int calculateDamage(int attackerAtk, int defenderDef);

    public: 
        virtual void drinkPotion(Potion& p); // drinks a potion and gains its effects
        PlayerCharacter(Position pos, int health = 125, int maxHealth = 125, 
            int atk = 25, int def = 25, int goldATM = 0, Race race = Race::SHADE, bool has_max_health = true);

        virtual ~PlayerCharacter(); // Virtual destructor for proper inheritance
        // Getters
        Position getPos();
        int getHealth();
        int getMaxHealth();
        bool HasMaxHealth();
        int getAtk();
        int getDef();
        int getGoldATM();
        Race getRace();
        void addGold(int amount);
        // Virtual methods that races can override
        virtual void attack(Enemy& enemy);
        
        void takeDamage(int damage);  // Method for taking damage from enemies
};


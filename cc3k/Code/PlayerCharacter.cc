export PlayerCharacter;

export class PlayerCharacter {
    // representing the PC's position on the floor
    int row; 
    int col;
    int heath; // representing the HP
    int maxHealth; // representing the max HP
    bool has_max_health; // representing if the PC has the max health - reserved for Vampire.
    int atk; // representing the attack power
    int def; // representing the defense power
    int goldATM; // representing the gold of the PC
    public: 
        void drinkPotion(Potion p); // drinks a potion and gains its effects
        virtual PlayerCharacter(int row, int col, int health, int maxHealth, bool has_max_health, 
            int atk, int def, int goldATM);
        int getRow();
        int getCol();
        int getHealth();
        int getMaxHealth();
        bool getHasMaxHealth();
        int getAtk();
        int getDef();
        int getGoldATM();
};












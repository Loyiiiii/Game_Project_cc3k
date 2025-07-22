export module merchant;
import PlayerCharacter;
import Global_Constants;
import Enemy;
import MerchantHoard;

// Merchant Hoard is dropped upon the death of the merchant. 
// Merchant drops 1 merchant hoard when dead (4 gold). 
export class Merchant: public Enemy {
    bool is_hostile; // if is true, merchant will attack player after being attacked. 
    std::unique_ptr<MerchantHoard> mer_hoard; // takes ownership of merchant hoard. 
    static bool remainingMerchantHostile; // if true, all remaining merchant will be hostile. 
    public:
        Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard);
        void attack(PlayerCharacter& pc) override;
        void dropGold(PlayerCharacter& pc) override;
        void setHostile(); // change is_neutral to false. 
        void takeDamage(int dmg) override;
};


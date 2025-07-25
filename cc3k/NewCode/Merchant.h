#ifndef MERCHANT_H
#define MERCHANT_H

#include <memory>
#include "Enemy.h"
#include "MerchantHoard.h"

class PlayerCharacter; // forward declaration

// Merchant Hoard is dropped upon the death of the merchant. 
// Merchant drops 1 merchant hoard when dead (4 gold). 
class Merchant : public Enemy {
    bool is_hostile;// if is true, merchant will attack player after being attacked. 
    std::unique_ptr<MerchantHoard> mer_hoard; // takes ownership of merchant hoard. 
    static bool remainingMerchantHostile; // if true, all remaining merchant will be hostile. 

public:
    Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard);
    std::string attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void setHostile();
    void takeDamage(int dmg) override;
    static void setAllHostile();
    bool getMoveStatus() const override;
};

#endif 

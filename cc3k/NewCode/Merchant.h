#ifndef MERCHANT_H
#define MERCHANT_H

#include <memory>
#include "Enemy.h"
#include "MerchantHoard.h"

class PlayerCharacter;

class Merchant : public Enemy {
    bool is_hostile;
    std::unique_ptr<MerchantHoard> mer_hoard;
    static bool remainingMerchantHostile;

public:
    Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard);
    void attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void setHostile();
    void takeDamage(int dmg) override;
    static void setAllHostile();
};

#endif 
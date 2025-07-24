#include "Merchant.h"
#include "PlayerCharacter.h"
#include "MerchantHoard.h"

// first initizlied to false. 
bool Merchant::remainingMerchantHostile = false;

Merchant::Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard) :
    // superclass ctor runs
    // first initizlied to true -> merchant is neutral. 
    Enemy{ pos, 30, 70, 5, true, true, 'M' },
    is_hostile{false},
    mer_hoard{std::move(m_hoard)} {
    mer_hoard->setIsPickable(false); // merchant is alive, hoard is not pickable. 
}

void Merchant::attack(PlayerCharacter& pc) {
    if (is_hostile || remainingMerchantHostile) {
        int damage = calculateDamage(getAtk(), pc.getDef());
        pc.takeDamage(damage);
    }
}

// when merchant is dead, hoard is pickable. 
void Merchant::dropGold(PlayerCharacter& pc) {
    mer_hoard->setIsPickable(true);
}

void Merchant::setHostile() {
    is_hostile = true;
    is_neutral = false;
    remainingMerchantHostile = true;
}


void Merchant::takeDamage(int dmg) {
    // once taken damage, merchant will be hostile. 
    setHostile();
    if (getHP() - dmg <= 0) {
        setHP(0); // merchant is dead. 
    }
    else {
        setHP(getHP() - dmg);
    }
}

void Merchant::setAllHostile() {
    remainingMerchantHostile = true;
} 

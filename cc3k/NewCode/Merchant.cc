#include "Merchant.h"
#include "PlayerCharacter.h"
#include "MerchantHoard.h"
#include <string>

// first initizlied to false. 
bool Merchant::remainingMerchantHostile = false;

Merchant::Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard) :
    // superclass ctor runs
    // first initizlied to true -> merchant is neutral. 
    Enemy{ pos, 30, 70, 5, false, true, 'M' },
    is_hostile{false},
    mer_hoard{std::move(m_hoard)} {
    mer_hoard->setIsPickable(false); // merchant is alive, hoard is not pickable. 
}

std::string Merchant::attack(PlayerCharacter& pc) {
    if (is_hostile || remainingMerchantHostile) {
        int damage = calculateDamage(getAtk(), pc.getDef());
        pc.takeDamage(damage);
        std::string msg = std::string(1, this->getSymbol()) + " deals " + std::to_string(damage) + " damage to PC. ";
        return msg;
    }
    return "";
}

// when merchant is dead, hoard is pickable. 
void Merchant::dropGold(PlayerCharacter& pc) {
    mer_hoard->setIsPickable(true);
}

void Merchant::setHostile() {
    is_hostile = true;
    is_neutral = false;
    setAllHostile(); // set all remaining merchant to hostile. 
    //setMovable(true); // set all
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

bool Merchant::getMoveStatus() const {
    return is_hostile || remainingMerchantHostile;
}

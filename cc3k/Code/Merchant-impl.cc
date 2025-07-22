module merchant;
import PlayerCharacter;
import Global_Constants;
import Enemy;
import MerchantHoard;

// first initizlied to false. 
bool Merchant::remainingMerchantHostile = false;

Merchant::Merchant(Position pos, std::unique_ptr<MerchantHoard> m_hoard):
    // first made merchant neutral. 
    Enemy{pos, 30, 70, 5, true, true, 'M'},
    is_hostile{false},
    // transfer ownership of merchant hoard. 
    mer_hoard{std::move(m_hoard)} {
        mer_hoard->setIsPickable(false); // merchant is alive, hoard is not pickable. 
    }

void Merchant::attack(PlayerCharacter& pc) {
    if (is_hostile || remainingMerchantHostile) {
        int damage = calculateDamage(this->Atk, pc.getDef());
        pc.takeDamage(damage);
    }
}

void Merchant::dropGold(PlayerCharacter& pc) {
    mer_hoard->setIsPickable(true); // merchant is dead, hoard is pickable. 
}

void Merchant::setHostile() {
    is_hostile = true;
    is_neutral = false;
}

void Merchant::takeDamage(int dmg) {
    // once taken damage, merchant will be hostile. 
    setHostile();
    remainingMerchantHostile = true; // all remaining merchant will be hostile. 
    if (this->getHP() - dmg <= 0) {
        HP = 0; // merchant is dead. 
    }
    else {
        HP -= dmg;
    }
}

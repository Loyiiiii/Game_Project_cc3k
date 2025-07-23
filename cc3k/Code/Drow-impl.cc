module Drow;
import PlayerCharacter;
import Global_Constants;

Drow::Drow():
    PlayerCharacter{150, 150, 25, 15, 0, Race::DROW, true} {}

void Drow::drinkPotion(Potion& p) {
    // all potions have effect magnified by 1.5x
    float after_enhancement = p.getAmount() * potion_effect_enhancement;

    // first add the potion consumed to the container.
    PotionInUse.emplace(p);
    // Positive effects:
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        // HP capped at 150 
        if (health + after_enhancement > maxHealth) {
            health = maxHealth;
        }
        else {
            health += after_enhancement; 
        }
    }
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        atk += after_enhancement;
    }
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        def += after_enhancement;
    }
    // Negative effects:
    else if (p.getType() == Potion_Type::POISION_HEALTH) {
        if (health + after_enhancement < 0) {
            health = 0;  // can't be negative -> the PC is dead.
        }
        else {
            health += after_enhancement; // we will add the negative effect - the potion will -10 HP.
        }
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        atk += after_enhancement; // we will add the negative effect - the potion will -5 Atk.
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        def += after_enhancement; // we will add the negative effect - the potion will -5 Def.
    }
}

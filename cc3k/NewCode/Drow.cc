#include "Drow.h"
#include "PlayerCharacter.h"
#include "Global_Constants.h"
#include "Potion.h"

Drow::Drow() :
    // superclass ctor runs 
    PlayerCharacter{ 150, 150, 25, 15, 0, Race::DROW, true} {}

// override the drinkPotion method 
void Drow::drinkPotion(Potion& p) {

    float after_enhancement = p.getAmount() * potion_effect_enhancement;

    PotionInUse.push_back(p); // add the potion to the effect in use list

    // Positive Effects: 
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        if (getHP() + after_enhancement > getMaxHP()) {
            setHP(getMaxHP());
        }
        else {
            setHP(getHP() + after_enhancement);
        }
    }
    // ATK_BOOST
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        setAtk(getAtk() + after_enhancement);
    }
    // DEF_BOOST
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        setDef(getDef() + after_enhancement);
    }
    else if (p.getType() == Potion_Type::POISON_HEALTH) {
        if (getHP() + after_enhancement < 0) {
            setHP(0);
        }
        else {
            setHP(getHP() + after_enhancement);
        }
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        setAtk(getAtk() + after_enhancement);
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        setDef(getDef() + after_enhancement);
    }
} 

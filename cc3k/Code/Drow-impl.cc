module Drow;

Drow::Drow(Position pos):
    PlayerCharacter(pos, 150, 150, 25, 15, 0, Race::DROW) {}

void Drow::drinkPotion(Potion p) {
    // all potions have effect magnified by 1.5x

    // first add the potion consumed to the container.
    PotionInUse.emplace(p);
    // then, similar to PC base, we only need to 
    // modify the potion's effect by 1.5x.
    if (p.getType() == Potion_Type::HEALTH_RESTORE) {
        // ...
    }
    else if (p.getType() == Potion_Type::ATK_BOOST) {
        // ...
    }
    else if (p.getType() == Potion_Type::DEF_BOOST) {
        // ...
    }
    // Negative effects:
    else if (p.getType() == Potion_Type::POISION_HEALTH) {
        // ...
    }
    else if (p.getType() == Potion_Type::WOUND_ATK) {
        // ...
    }
    else if (p.getType() == Potion_Type::WOUND_DEF) {
        // ...
    }
}

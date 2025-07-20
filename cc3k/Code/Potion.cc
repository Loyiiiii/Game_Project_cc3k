export module potion;

import Global_Constants;

export class Potion : public Item {
    Potion_Type type;
    bool isTemporary; // whether the potion is temporary or permanent
    int amount; // the amount of the potion effect
    char symbol; // for displaying the potion in the map

public:
    Potion(Potion_Type type, bool isTemporary, int amount, char symbol);
    virtual ~Potion();

    Potion_Type getType() const;
    int getAmount() const;
    char getSymbol() const;
}

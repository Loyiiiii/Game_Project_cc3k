export module potion;

import item;
import Global_Constants;

export class Potion {
    Potion_Type type;
    bool isTemporary; // whether the potion is temporary or permanent
    int amount; // the amount of the potion effect
    char symbol; // for displaying the potion in the map

public:
    Potion(bool isPickable, Potion_Type type, bool isTemporary, int amount, char symbol);
    virtual ~Potion() = default;

    Potion_Type getType() const;
    bool getIsTemporary() const;
    int getAmount() const;
    char getSymbol() const;
};

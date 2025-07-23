module potion;

Potion::Potion(bool isPickable, Potion_Type type, bool isTemporary, int amount, char symbol)
    : Item{isPickable}, type{type}, isTemporary{isTemporary}, amount{amount}, symbol{symbol}, isPickable{isPickable} {}

Potion_Type Potion::getType() const {
    return type;
}

bool Potion::getIsTemporary() const {
    return isTemporary;
}

int Potion::getAmount() const {
    return amount;
}

char Potion::getSymbol() const {
    return symbol;
}

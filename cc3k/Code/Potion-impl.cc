module potion;

Potion::Potion(Potion_Type type, bool isTemporary, int amount, char symbol)
    : type(type), isTemporary(isTemporary), amount(amount), symbol(symbol) {}

Potion::~Potion() {}

Potion_Type Potion::getType() const {
    return type;
}

int Potion::getAmount() const {
    return amount;
}

char Potion::getSymbol() const {
    return symbol;
}

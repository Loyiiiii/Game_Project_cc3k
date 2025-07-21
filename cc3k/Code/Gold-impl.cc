module gold;

Gold::Gold(int value, bool isPickable): value{value}, isPickable{isPickable} {
    // Constructor to initialize gold with a value and symbol
}

int Gold::getValue() const {
    return value; // Getter for the value of gold
}

char Gold::getSymbol() const {
    return symbol; // Getter for the symbol of gold
}

bool Gold::getIsPickable() const {
    return isPickable; // Getter for pickability of gold
}

void Gold::setIsPickable(bool pickable) {
    isPickable = pickable; // Setter for pickability of gold
    // Dragon Hoard is initially unpickable, but can be made pickable later
}

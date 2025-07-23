module gold;

Gold::Gold(int value, bool isPickable):
    Item{isPickable}, value{value} {}

int Gold::getValue() const {
    return value; // return the value of gold. 
}

char Gold::getSymbol() const {
    return symbol; // return the symbol of gold. 
}

bool Gold::getIsPickable() const {
    return isPickable; // return the pickability of gold. 
}

void Gold::setIsPickable(bool pickable) {
    isPickable = pickable; // set the pickability of gold. 
    // Dragon Hoard is initially unpickable, but can be made pickable later. 
}

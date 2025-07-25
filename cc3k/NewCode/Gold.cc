#include "Gold.h"

Gold::Gold(int value, bool isPickable) :
    value{ value }, isPickable{ isPickable } {}

int Gold::getValue() const {
    return value;
}

char Gold::getSymbol() const {
    return symbol;
}

bool Gold::getIsPickable() const {
    return isPickable;
}

void Gold::setIsPickable(bool pickable) {
    isPickable = pickable;
} 

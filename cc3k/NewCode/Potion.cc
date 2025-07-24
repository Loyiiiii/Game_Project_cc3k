#include "Potion.h"

Potion::Potion(Potion_Type type, bool isTemporary, int amount, char symbol)
    : type{ type }, isTemporary{ isTemporary }, amount{ amount }, symbol{ symbol } {}

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

int Potion::setAmount(int newAmount) {
    amount = newAmount;
    return amount;
}

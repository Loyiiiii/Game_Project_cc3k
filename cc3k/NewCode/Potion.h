#ifndef POTION_H
#define POTION_H

#include "Global_Constants.h"

class Potion {
    Potion_Type type;
    bool isTemporary;
    int amount;
    char symbol;

public:
    Potion(Potion_Type type, bool isTemporary, int amount, char symbol);
    virtual ~Potion() = default;

    Potion_Type getType() const;
    bool getIsTemporary() const;
    int getAmount() const;
    char getSymbol() const;
    int setAmount(int newAmount);
};

#endif 

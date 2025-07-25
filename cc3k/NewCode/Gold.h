#ifndef GOLD_H
#define GOLD_H

class Gold {
    int value;
    char symbol = 'G';
    bool isPickable;

public:
    Gold(int value, bool isPickable);
    virtual ~Gold() = default;

    int getValue() const;
    char getSymbol() const;
    bool getIsPickable() const;
    void setIsPickable(bool pickable);
};

#endif 

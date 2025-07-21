export module gold;

import item;

export class Gold : public Item {
    int value;
    char symbol = 'G'; // Symbol to represent gold in the game

public:
    Gold(int value, bool isPickable); // Constructor to initialize gold with a value and symbol
    virtual ~Gold() = default; // Virtual destructor for proper cleanup

    int getValue() const; // Getter for the value of gold
    char getSymbol() const; // Getter for the symbol of gold
    bool getIsPickable() const; // Getter for pickability of gold
    void setIsPickable(bool pickable); // Setter for pickability of gold
    // Dragon Hoard is initially unpickable, but can be made pickable later
};

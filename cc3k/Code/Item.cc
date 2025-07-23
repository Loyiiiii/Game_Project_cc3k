export module item;

export class Item {
protected:
    bool isPickable;

public:
    Item(bool isPickable);
    virtual ~Item() = default;

    bool getIsPickable() const;
    void setIsPickable(bool isPickable);
};

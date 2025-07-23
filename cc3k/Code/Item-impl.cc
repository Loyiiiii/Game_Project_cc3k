module item;

Item::Item(bool isPickable) : isPickable{isPickable} {}

bool Item::getIsPickable() const {
    return isPickable;
}

void Item::setIsPickable(bool isPickable) {
    this->isPickable = isPickable;
}

export module dwarf;

export class Dwarf : public Enemy {
public:
    Dwarf(Position pos, int HP, int Atk, int Def, bool movable, char symbol);

    void attack(PlayerCharacter& pc) override;
    void dropGold() override;
    char getSymbol() override;
}

module dwarf;

Dwarf::Dwarf(Position pos, int HP, int Atk, int Def, bool movable, char symbol): 
    Enemy{Pos, HP, Atk, Def, movable}, symbol{'W'} {}

// note: attack needs to incorporate damage calculation logic.
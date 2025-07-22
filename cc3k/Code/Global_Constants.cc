export module Global_Constants;


export enum class Race {
    SHADE, DROW, VAMPIRE, TROLL, GOBLIN
};


export enum class Potion_Type {
    HEALTH_RESTORE, ATK_BOOST,DEF_BOOST, POISON_HEALTH, WOUND_ATK, WOUND_DEF
};

export struct Position {
    int row;
    int col;
};

export enum class Direction {
    N, S, E, W, NE, NW, SE, SW
};

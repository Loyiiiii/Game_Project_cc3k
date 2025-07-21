export module Global_Constants;


export enum Race {
    SHADE, DROW, VAMPIRE, TROLL, GOBLIN
};


export enum Potion_Type {
    HEALTH_RESTORE, ATK_BOOST,DEF_BOOST, POISON_HEALTH, WOUND_ATK, WOUND_DEF
};

export struct Position {
    int row;
    int col;
};


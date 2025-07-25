#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row;
    int col;

    Position(int r, int c);

    bool operator==(const Position &other) const;

    bool operator!=(const Position &other) const;
};

#endif 

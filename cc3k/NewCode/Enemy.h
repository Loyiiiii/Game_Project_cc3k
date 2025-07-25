#ifndef ENEMY_H
#define ENEMY_H

#include "Position.h"
#include "Global_Constants.h"
#include <string>

class PlayerCharacter;

class Enemy {
protected:
    Position pos;
    int HP;
    int Atk;
    int Def;
    bool movable;
    bool is_neutral;
    char symbol;

    int calculateDamage(int attackAtk, int defenderDef);

public:
    Enemy(Position pos, int HP, int Atk, int Def, bool movable, bool is_neutral, char symbol);
    virtual ~Enemy();

    char getSymbol() const;
    bool is_alive() const;
    bool isAdjacentTo(const Position& pc_pos) const;
    void setPosition(Position newPos);
    void setHP(int hp);
    void setMovable(bool isMovable);

    virtual std::string attack(PlayerCharacter& pc) = 0;
    virtual void dropGold(PlayerCharacter& pc) = 0;
    virtual void takeDamage(int damage) = 0;

    int getAtk() const;
    int getDef() const;
    int getHP() const;
    virtual bool getMoveStatus() const;
    Position getPosition() const;
};

#endif 

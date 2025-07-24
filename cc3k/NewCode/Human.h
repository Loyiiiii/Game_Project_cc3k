#ifndef HUMAN_H
#define HUMAN_H

#include <vector>
#include <memory>
#include "Enemy.h"
#include "NormalGold.h"

class PlayerCharacter;

class Human : public Enemy {
private:
    std::vector<std::unique_ptr<NormalGold>> gold_carried;
public:
    Human(Position pos);
    ~Human();
    std::string attack(PlayerCharacter& pc) override; // attack PlayerCharacter - override 
    void dropGold(PlayerCharacter& pc) override; // drop gold - override
    void takeDamage(int damage) override; // receive damage from PC
};

#endif

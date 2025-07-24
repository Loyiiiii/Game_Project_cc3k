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
    void attack(PlayerCharacter& pc) override;
    void dropGold(PlayerCharacter& pc) override;
    void takeDamage(int damage) override;
};

#endif 
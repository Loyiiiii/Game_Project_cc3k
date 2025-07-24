#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "PlayerCharacter.h"
#include "Global_Constants.h"

class Vampire : public PlayerCharacter {
private:
    void gainHP();
public:
    Vampire();
    void attack(Enemy& enemy) override;
};

#endif 
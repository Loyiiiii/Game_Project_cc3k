#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <vector>
#include "Global_Constants.h"
#include "Position.h"
#include "Potion.h"

class Enemy;

class PlayerCharacter {
protected:
    Position pos;
    int health;
    int maxHealth;
    int atk;
    int def;
    int goldATM;
    Race race;
    bool has_max_health;
    std::vector<Potion> PotionInUse;

    int calculateDamage(int attackerAtk, int defenderDef);

public:
    PlayerCharacter(int health = 125, int maxHealth = 125,
        int atk = 25, int def = 25, int goldATM = 0, Race race = Race::SHADE, bool has_max_health = true);

    virtual ~PlayerCharacter();

    Position getPosition() const;
    int getHP() const;
    void setHP(int hp);
    int getMaxHP() const;
    bool hasMaxHealth() const;
    int getAtk() const;
    void setAtk(int new_atk);
    int getDef() const;
    void setDef(int new_def);
    int getGold() const;
    void addGold(int amount);
    Race getRace() const;

    void setPosition(Position newPos);

    virtual void attack(Enemy& enemy);
    virtual void drinkPotion(Potion& p);
    void takeDamage(int damage);
    bool isDead() const;
};

#endif 
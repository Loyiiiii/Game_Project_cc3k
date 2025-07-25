#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <vector>
#include "Global_Constants.h"
#include "Position.h"
#include "Potion.h"
#include <string>

class Enemy; // forward declaration

class PlayerCharacter {
protected:
    Position pos; // representing the position of the PC
    int health; // representing the health of the PC
    int maxHealth; // representing the max health of the PC
    int atk; // representing the attack power
    int def; // representing the defense power
    int goldATM; // representing the amount of gold that the PC has at the moment
    Race race; // representing the race of the PC
    bool has_max_health; // representing whether the PC has the max health - reserved for Vampire use (False)
    std::vector<Potion> PotionInUse; // representing the potions that the PC is using
    // formula: ceiling((100/(100 + Def (Defender))) * Atk(Attacker))
    int calculateDamage(int attackerAtk, int defenderDef); // calculating the damage that the PC deals to the enemy

public:
    // default to be Shade
    PlayerCharacter(int health = 125, int maxHealth = 125,
        int atk = 25, int def = 25, int goldATM = 0, Race race = Race::SHADE, bool has_max_health = true);

    virtual ~PlayerCharacter(); // destructor 
    bool hasMaxHealth() const;
    // getters:
    Position getPosition() const;
    int getHP() const;
    int getMaxHP() const;
    int getAtk() const;
    int getDef() const;
    int getGold() const;
    Race getRace() const;
    // setters:
    void addGold(int amount);
    void setHP(int hp);
    void setAtk(int new_atk);
    void setDef(int new_def);
    void setPosition(Position newPos);
    // virtual functions that to be overridden by subclasses
    virtual std::string attack(Enemy& enemy);
    virtual void drinkPotion(Potion& p);
    // take damage - same logic for all races 
    void takeDamage(int damage);
    // check if the PC is dead
    bool isDead() const;
    void clearTempPotionEffects();
};

#endif 

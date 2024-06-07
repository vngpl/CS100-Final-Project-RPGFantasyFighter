#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item{
public:
    Item(const std::string& name);
    std::string getName() const;
    virtual ~Item();

private:
    std::string name;
    int itemCount;
};

class Weapon : public Item{
public:
    enum class Type{
        Sword,
        Dagger,
        Wand
    };

    Weapon(Type type, int damage, int coinCost);
    Type getType() const;
    int getDamage() const;
    int getCoinCost() const;

private:
    Type type;
    int damage;
    int coinCost;
};

class Potion : public Item{
public:
    enum class Type{
        AttackBoost,
        HealthRecovery
    };

    Potion(Type type, int strength, int coinCost);
    Type getType() const;
    int getStrength() const;
    int getCoinCost() const; 

private:
    Type type;
    int strength;
    int coinCost; 
};

#endif
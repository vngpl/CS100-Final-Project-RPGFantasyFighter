#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item{
public:
    Item(const string& name);
    string getName() const;

private:
    string name;
};

class Weapon : public Item{
public:
    enum class Type{
        Sword,
        Dagger,
        Wand
    };

    Weapon(Type type, int damage);
    Type getType() const;
    int getDamage() const;

private:
    Type type;
    int damage;
};

class Potion : public Item{
public:
    enum class Type{
        AttackBoost,
        HealthRecovery
    };

    Potion(Type type, int strength);
    Type getType() const;
    int getStrength() const;

private:
    Type type;
    int strength;
};

#endif 
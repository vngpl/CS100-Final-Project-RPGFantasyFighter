#include "../header/Item.hpp"
#include <iostream>


Item::Item(const std::string& name) : name(name) {}
Item::~Item() {}

std::string Item::getName() const {
    return name;
}


Weapon::Weapon(Type type, int damage, int coinCost) 
    : Item("Weapon"), type(type), damage(damage), coinCost(coinCost) {}

Weapon::Type Weapon::getType() const {
    return type;
}

int Weapon::getDamage() const {
    return damage;
}

int Weapon::getCoinCost() const {
    return coinCost;
}


Potion::Potion(Type type, int strength, int coinCost) 
    : Item("Potion"), type(type), strength(strength), coinCost(coinCost) {}

Potion::Type Potion::getType() const {
    return type;
}

int Potion::getStrength() const {
    return strength;
}

int Potion::getCoinCost() const {
    return coinCost;
}
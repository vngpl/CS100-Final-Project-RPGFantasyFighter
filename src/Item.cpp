#include "../header/Item.h"
#include <iostream>


Item::Item(const std::string& name) : name(name) {}

std::string Item::getName() const {
    return name;
}


Weapon::Weapon(Type type, int damage) 
    : Item("Weapon"), type(type), damage(damage) {}

Weapon::Type Weapon::getType() const {
    return type;
}

int Weapon::getDamage() const {
    return damage;
}


Potion::Potion(Type type, int strength) 
    : Item("Potion"), type(type), strength(strength) {}

Potion::Type Potion::getType() const {
    return type;
}

int Potion::getStrength() const {
    return strength;
}
#include "../header/Item.hpp"

Item::Item(int strength, int cost) : strength(strength), cost(cost) { }

int Item::getStrength() const { return strength; }
int Item::getCost() const { return cost; }
void Item::setStrength(int newStrength) { strength = newStrength; }
void Item::setCost(int newCost) { cost = newCost; }

Sword::Sword() : Item(30, 1) { }
std::string Sword::getType() const { return "SWORD"; }

Dagger::Dagger() : Item(35, 2) { }
std::string Dagger::getType() const { return "DAGGER"; }

Wand::Wand() : Item(50, 3) { }
std::string Wand::getType() const { return "WAND"; }

HealthPotion::HealthPotion() : Item(50, 1) { }
std::string HealthPotion::getType() const { return "HEALTH__POTION"; }

AttackPotion::AttackPotion() : Item(10, 2) { }
std::string AttackPotion::getType() const { return "ATTACK_POTION"; }
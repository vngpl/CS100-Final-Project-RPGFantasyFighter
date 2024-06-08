#include <cstdlib>
#include <ctime>
#include "../header/Item.hpp"

Item::Item(int strength, int cost) : strength(strength), cost(cost) { }

int Item::getStrength() const { return strength; }
int Item::getCost() const { return cost; }
void Item::setStrength(int newStrength) { strength = newStrength; }
void Item::setCost(int newCost) { cost = newCost; }

Item* Item::generateRandomItem() {
    srand(time(0));
    int randNum = rand() % 5;

    switch (randNum) {
        case 0: return new Sword();
        case 1: return new Dagger();
        case 2: return new Wand();
        case 3: return new HealthPotion();
        case 4: return new AttackPotion();
        default: return nullptr;
    }
}

Sword::Sword() : Item(30, 1) { }
std::string Sword::getType() const { return "SWORD"; }

Dagger::Dagger() : Item(35, 2) { }
std::string Dagger::getType() const { return "DAGGER"; }

Wand::Wand() : Item(50, 3) { }
std::string Wand::getType() const { return "WAND"; }

HealthPotion::HealthPotion() : Item(50, 1) { }
std::string HealthPotion::getType() const { return "HEALTH_POTION"; }

AttackPotion::AttackPotion() : Item(10, 2) { }
std::string AttackPotion::getType() const { return "ATTACK_POTION"; }

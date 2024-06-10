#include <cstdlib>
#include <ctime>
#include "../header/Item.hpp"

Item::Item(int strength, int cost, const std::string& type) : strength(strength), cost(cost), type(type) { }

int Item::getStrength() const { return strength; }
int Item::getCost() const { return cost; }
void Item::setStrength(int newStrength) { strength = newStrength; }
void Item::setCost(int newCost) { cost = newCost; }
const std::string& Item::getType() const { return type; }

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

Sword::Sword() : Item(30, 1, "SWORD") { }
Dagger::Dagger() : Item(35, 2, "DAGGER") { }
Wand::Wand() : Item(50, 3, "WAND") { }
HealthPotion::HealthPotion() : Item(50, 1, "HEALTH_POTION") { }
AttackPotion::AttackPotion() : Item(10, 2, "ATTACK_POTION") { }

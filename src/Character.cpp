#include "../header/Character.hpp"

Character::Character(int health, double attackStrength)
    : health(health), attackStrength(attackStrength), MAX_HEALTH(health), level(5), experience(0.0), monstersSlain(0), coins(0) { }

int Character::getHealth() const { return health; }
int Character::getLevel() const { return level; }
int Character::getMonstersSlain() const { return monstersSlain; }
int Character::getCoins() const { return coins; }
double Character::getExperience() const { return experience; }
double Character::getAttackStrength() const { return attackStrength; }

void Character::setHealth(int newHealth) { health = newHealth; }
void Character::updateMonsterSlainCount() { monstersSlain++; }
void Character::setCoins(int newCoins) { coins = newCoins; }
void Character::setExperience(double newExperience) { experience = newExperience; }
void Character::setAttackStrength(double newAttackStrength) { attackStrength = newAttackStrength; }

bool Character::inventoryIsEmpty() { return inventory.IsEmpty(); }
bool Character::inventoryOnlyPotion() { return inventory.OnlyPotion(); }
bool Character::inventoryOnlyWeapon() { return inventory.OnlyWeapon(); }

bool Character::isDead() const { return health <= 0; }

void Character::useItem(int itemIndex) {
    Item* itemToUse = inventory.getItem(itemIndex);

    if (itemToUse == nullptr) {
        std::cerr << "Error: ITEM NOT FOUND IN INVENTORY AT INDEX " << itemIndex << std::endl;
        return;
    }

    int newAttributeValue = 0;

    if ((itemToUse->getType() == "SWORD" && getType() == "WARRIOR") ||
        (itemToUse->getType() == "DAGGER" && getType() == "ASSASSIN") ||
        (itemToUse->getType() == "WAND" && getType() == "WIZARD")) {
        newAttributeValue = getAttackStrength() + static_cast<double>(itemToUse->getStrength()) + 15;
    }
    else {
        newAttributeValue = getAttackStrength() + static_cast<double>(itemToUse->getStrength());
    }

    if (itemIndex == 0) {
        setAttackStrength(newAttributeValue);
    }
    else {
        setHealth(newAttributeValue);
    }

    inventory.useItem(itemIndex);
}







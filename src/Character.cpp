#include "../header/Character.hpp"

Character::Character(int health, double attackStrength, int level,
                     const std::string& type)
    : health(health),
      attackStrength(attackStrength),
      level(level),
      type(type),
      MAX_HEALTH(health),
      experience(0.0),
      monstersSlain(0),
      coins(0),
      inventory(2, nullptr) {}

Character::~Character() {
  // for (Item*& item : inventory) {
  //   delete item;
  //   item = nullptr;
  // }
  // inventory.clear();
  delete inventory.at(0);
  delete inventory.at(1);
}

int Character::getHealth() const {
  return health;
}
int Character::getMaxHealth() const {
  return MAX_HEALTH;
}
int Character::getLevel() const {
  return level;
}
int Character::getMonstersSlain() const {
  return monstersSlain;
}
int Character::getCoins() const {
  return coins;
}
double Character::getExperience() const {
  return experience;
}
double Character::getNextExperience() const {
  return nextExperience;
}  // NEW
double Character::getAttackStrength() const {
  return attackStrength;
}
const std::string& Character::getType() const {
  return type;
}
const std::vector<Item*>& Character::getInventoryItems() const {
  return inventory;
}

void Character::setHealth(int newHealth) {
  health = newHealth;
}
void Character::updateMonsterSlainCount() {
  monstersSlain++;
}
void Character::setCoins(int newCoins) {
  coins = newCoins;
}
void Character::setExperience(double newExperience) {
  experience = newExperience;
}
void Character::setNextExperience(double newNextExperience) {
  nextExperience = newNextExperience;
}  // NEW
void Character::setLevel(int newLevel) {
  level = newLevel;
}
void Character::setAttackStrength(double newAttackStrength) {
  attackStrength = newAttackStrength;
}

bool Character::inventoryIsEmpty() const {
  return (inventory.at(0) == nullptr && inventory.at(1) == nullptr);
}
bool Character::hasWeapon() const {
  return inventory.at(0) != nullptr;
}
bool Character::hasPotion() const {
  return inventory.at(1) != nullptr;
}
bool Character::isDead() const {
  return health <= 0;
}

void Character::addItem(Item* item) {
  if (item->getType() == "SWORD" || item->getType() == "DAGGER" ||
      item->getType() == "WAND") {
    inventory.at(0) = item;
  } else {
    inventory.at(1) = item;
  }
}

void Character::useItem(int itemIndex) {
  Item* itemToUse = inventory.at(itemIndex);

  if (itemToUse == nullptr) {
    std::cerr << "Error: ITEM NOT FOUND IN INVENTORY AT INDEX " << itemIndex
              << std::endl;
    return;
  }

  int newAttributeValue = 0;

  if ((itemToUse->getType() == "SWORD" && getType() == "WARRIOR") ||
      (itemToUse->getType() == "DAGGER" && getType() == "ASSASSIN") ||
      (itemToUse->getType() == "WAND" && getType() == "WIZARD")) {
    newAttributeValue = getAttackStrength() +
                        static_cast<double>(itemToUse->getStrength()) + 15;
  } else {
    newAttributeValue =
        getAttackStrength() + static_cast<double>(itemToUse->getStrength());
  }

  if (itemIndex == 0) {
    setAttackStrength(newAttributeValue);
  } else {
    setHealth(newAttributeValue);
  }

  delete inventory.at(itemIndex);
  inventory.at(itemIndex) = nullptr;
}

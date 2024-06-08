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

// void Character::useItem(int itemIndex) {
//     Item* testItem = new Item();
//     int newValue = 0;

//     testItem = inventory.getItem(itemIndex);

//     if (static_cast<Weapon>(item)->getType() == Weapon::Type::Sword){
//         if (getType() == WARRIOR){
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage() + 15;
//         }
//         else {
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage();
//         }
//         setAttackStrength(newValue);
//     }
//     else if (static_cast<Weapon>(item)->getType() == Weapon::Type::Dagger){
//         if (getType() == ASSASSIN){
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage() + 15;
//         }
//         else {
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage();
//         }
//         setAttackStrength(newValue);
//     }
//     else if (static_cast<Weapon>(item)->getType() == Weapon::Type::Wand){
//         if (getType() == WIZARD){
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage() + 15;
//         }
//         else {
//             newValue = getAttackStrength() + static_cast<Weapon>(item)->getDamage();
//         }
//         setAttackStrength(newValue);
//     }
//     else if (static_cast<Potion>(item)->getType() == Potion::Type::AttackBoost){
//         newValue = getAttackStrength() + static_cast<Potion>(item)->getStrength();
//         setAttackStrength(newValue);
//     }
//     else if (static_cast<Potion>(item)->getType() == Potion::Type::HealthRecovery){
//         newValue = getHealth() + static_cast<Potion>(item)->getStrength();
//         setHealth(newValue);
//     }

//     inventory.useItem(itemIndex);
// }







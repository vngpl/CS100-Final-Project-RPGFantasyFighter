#include "header/Character.hpp"

Character::Character(CharacterType type, const std::string& name, double health, double attackStrength)
    : type(type), name(name), health(health), attackStrength(attackStrength) { }

CharacterType& Character::getType() const { return type; }

const std::string& Character::getName() const { return name; }

int Character::getHealth() const { return static_cast<int>(health); }

int Character::getLevel() const { return level; }

double Character::getExperience() const { return experience; }

double Character::getAttackStrength() const { return attackStrength; }

void Character::setHealth(int newHealth) { health = newHealth; }

void Character::setExperience(double newExperience) { experience = newExperience; }

void Character::useItem(Item* consumable) { inventory.useItem(consumable); }

bool Character::isDead() const { return getHealth() <= 0; }



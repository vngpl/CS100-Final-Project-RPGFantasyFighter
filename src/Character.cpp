#include "header/Character.hpp"

Character::Character(CharacterType type, const std::string& name, double health, double attackStrength) 
    : type(type), name(name), health(health), attackStrength(attackStrength) { }

CharacterType Character::getType() const { return type; }

const std::string& Character::getName() const { return name; }
int Character::getHealth() const { return static_cast<int>(health); }
int Character::getLevel() const { return level; }
double Character::getExperience() const { return experience; }
double Character::getAttackStrength() const { return attackStrength; }
bool Character::isDead() const { return getHealth() <= 0; }

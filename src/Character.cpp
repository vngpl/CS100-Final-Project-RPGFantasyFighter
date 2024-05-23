#include "header/Character.hpp"

Character::Character(CharacterType type, const std::string& name, double health, double experience, double attackStrength) 
    : type(type), name(name), health(health), experience(experience), attackStrength(attackStrength) { }

CharacterType Character::getType() const { return type; }

const std::string& Character::getName() const { return name; }

int Character::getHealth() const { return static_cast<int>(health); }

double Character::getExperience() const { return experience; }

double Character::getAttackStrength() const { return attackStrength; }

bool Character::isDead() const { return getHealth() <= 0; }

#include "header/Character.hpp"

Character::Character(const std::string& name, double health = 100, double experience = 0, double attackStrength = 0) 
    : name(name), health(health), experience(experience), attackStrength(attackStrength) {}

std::string Character::getName() const { return name; }
int Character::get
double Character::getHealth() const { return health; }
double Character::getExperience() const { return experience; }
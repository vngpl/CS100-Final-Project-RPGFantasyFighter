#include "header/Wizard.hpp"
#include <stdexcept>

Wizard::Wizard(const std::string& name, int health = 100, double attackStrength = 100.0)
    : Character(WIZARD, name, health, attackStrength), maxHealth(health) { }

// void attack(Character& opponent) {
//     throw std::runtime_error("finish Wizard attack");
// }
#include "header/Warrior.hpp"
#include <stdexcept>

Warrior::Warrior(const std::string& name, int health = 125, double attackStrength = 100.0)
    : Character(WARRIOR, name, health, attackStrength), maxHealth(health) { }

// void attack(Character& opponent) {
//     throw std::runtime_error("finish Warrior attack");
// }
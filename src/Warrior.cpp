#include "header/Warrior.hpp"
#include <stdexcept>

Warrior::Warrior(const std::string& name, int health = 125, double experience = 100.0, double attackStrength = 100.0)
    : Character(WARRIOR, name, health, experience, attackStrength) { }

void attack(Character& opponent) {
    throw std::runtime_error("finish Warrior attack");
}
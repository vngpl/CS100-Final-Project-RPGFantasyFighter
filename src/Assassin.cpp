#include "header/Assassin.hpp"
#include <stdexcept>

Assassin::Assassin(const std::string& name, int health = 90, double attackStrength = 120.0)
    : Character(ASSASSIN, name, health, attackStrength) { }

void attack(Character& opponent) {
    throw std::runtime_error("finish Assassin attack");
}
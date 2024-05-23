#include "header/Assassin.hpp"
#include <stdexcept>

Assassin::Assassin(const std::string& name, int health = 100, double experience = 100.0, double attackStrength = 125.0)
    : Character(ASSASSIN, name, health, experience, attackStrength) { }

void attack(Character& opponent) {
    throw std::runtime_error("finish Assassin attack");
}
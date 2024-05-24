#include "header/Monster.hpp"

Monster::Monster(const std::string& name, int health = 100, int level = 1, double attackStrength = 100)
    : Enemy(MONSTER, name, health, level, attackStrength) { }

void Monster::attack(Character& target) { 
    throw std::runtime_error("finish monster attack");
}
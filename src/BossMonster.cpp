#include "header/BossMonster.hpp"

BossMonster::BossMonster(const std::string& name, int health = 200, int level = 2, double attackStrength = 100.0) 
    : Monster(name, health, level, attackStrength) { }

void BossMonster::performSpecialAbility(Character& target) {
    throw std::runtime_error("finish boss monster special ability");
}
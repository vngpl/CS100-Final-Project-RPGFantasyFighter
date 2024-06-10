#include "../header/Enemy.hpp"

Enemy::Enemy(int health, double attackStrength, const std::string& type)
    : health(health), attackStrength(attackStrength), type(type), level(5) { }

int Enemy::getHealth() const { return health; }
int Enemy::getLevel() const { return level; }
double Enemy::getAttackStrength() const { return attackStrength; }
const std::string& Enemy::getType() const { return type; }

void Enemy::setHealth(int newHealth) { health = newHealth; }
// void Enemy::setLevel(int newLevel) { level = newLevel; }
void Enemy::setAttackStrength(double newAttackStrength) { attackStrength = newAttackStrength; }

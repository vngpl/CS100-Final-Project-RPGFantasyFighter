#include "../header/Enemy.hpp"

Enemy::Enemy()
    : health(1), attackStrength(1.0), type("Normal"), level(1) {}

Enemy::Enemy(int health, double attackStrength, int level, const std::string& type)
    : health(health), attackStrength(attackStrength), type(type), level(level) {}

int Enemy::getHealth() const {
  return health;
}
int Enemy::getLevel() const {
  return level;
}
double Enemy::getAttackStrength() const {
  return attackStrength;
}
const std::string& Enemy::getType() const {
  return type;
}

void Enemy::setHealth(int newHealth) {
  health = newHealth;
}

void Enemy::setLevel(int newLevel) {
  level = newLevel;
}

void Enemy::setAttackStrength(double newAttackStrength) {
  attackStrength = newAttackStrength;
}

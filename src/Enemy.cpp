#include "../header/Enemy.hpp"

Enemy::Enemy(int health, double attackStrength)
    : health(health), attackStrength(attackStrength), level(5) { }

int Enemy::getHealth() const { return health; }
int Enemy::getLevel() const { return level; }
double Enemy::getAttackStrength() const { return attackStrength; }

void Enemy::setHealth(int newHealth) { health = newHealth; }
void Enemy::setLevel(int newLevel) { level = newLevel; }
void Enemy::setAttackStrength(double newAttackStrength) { attackStrength = newAttackStrength; }

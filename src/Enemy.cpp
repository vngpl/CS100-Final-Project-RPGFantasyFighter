#include "header/Enemy.hpp"

Enemy::Enemy(const std::string& name, int health, int level, double attackStrength)
    : name(name), health(health), level(level), attackStrength(attackStrength) { }

EnemyType Enemy::getEnemyType() const { return EnemyType; }

const std::string& Enemy::getName() const { return name; }

int Enemy::getHealth() const { return health; }

int Enemy::getLevel() const { return level; }

double Enemy::getAttackStrength() const { return attackStrength; }


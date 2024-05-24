#include "header/Enemy.hpp"

Enemy::Enemy(EnemyType type, const std::string& name, int health, int level, double attackStrength)
    : type(type), name(name), health(health), level(level), attackStrength(attackStrength) { }

EnemyType Enemy::getEnemyType() const { return type; }

const std::string& Enemy::getName() const { return name; }

int Enemy::getHealth() const { return health; }

int Enemy::getLevel() const { return level; }

double Enemy::getAttackStrength() const { return attackStrength; }


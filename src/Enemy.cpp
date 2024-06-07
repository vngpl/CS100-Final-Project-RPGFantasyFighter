#include "../header/Enemy.hpp"

Enemy::Enemy(EnemyType type, int health, double attackStrength)
    : type(type), health(health), attackStrength(attackStrength), level(5) { }

const std::string& Enemy::getEnemyType() const {
    switch (type) {
        case MONSTER:
            return "MONSTER";
        default:
            return "UNSPECIFIED ENEMY TYPE";
    }
}

int Enemy::getHealth() const { return health; }
int Enemy::getLevel() const { return level; }
double Enemy::getAttackStrength() const { return attackStrength; }

void Enemy::setHealth(int newHealth) { health = newHealth; }
// void Enemy::setLevel(int newLevel) { level = newLevel; }
void Enemy::setAttackStrength(double newAttackStrength) { attackStrength = newAttackStrength; }

#include <iostream>
#include <string>

using namespace std;

// #include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Diffi.hpp"

std::vector<Enemy*> Difficulty::allEnemies;

void Difficulty::setEasy() {
    for (Enemy* enemy : allEnemies) {
            // Update health and attack strength for each enemy
            enemy->setHealth(enemy->getHealth() * 0.5);
            enemy->setAttackStrength(enemy->getAttackStrength() * 0.5);
    }
}

void Difficulty::setNormal() {    
    // Stays the same lol
}

void Difficulty::setHard() {
    for (Enemy* enemy : allEnemies) {
            // Update health and attack strength for each enemy
            enemy->setHealth(enemy->getHealth() * 1.5);
            enemy->setAttackStrength(enemy->getAttackStrength() * 1.5);
    }
}

void Difficulty::addEnemy(Enemy* enemy) {
    allEnemies.push_back(enemy);
}
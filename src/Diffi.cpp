#include <iostream>
#include <string>

// using namespace std;

// #include "../header/Character.hpp"
#include "../header/Diffi.hpp"
#include "../header/Enemy.hpp"

// std::vector<Enemy*> Difficulty::allEnemies;

Difficulty::Difficulty() : diffi_level(-1) {}

void Difficulty::setLevel(int32_t level) {
  diffi_level = level;
}

bool Difficulty::levelSettled() const {
  return (diffi_level != -1);
}

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

// void Difficulty::addEnemy(Enemy* enemy) {
//     allEnemies.push_back(enemy);
// }

void Difficulty::setEnemies(const std::vector<Enemy*>& enemies) {
  allEnemies = std::move(enemies);
  // TODO: Set difficulties
}
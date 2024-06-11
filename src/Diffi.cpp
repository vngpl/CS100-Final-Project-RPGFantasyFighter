#include "../header/Diffi.hpp"

#include <cassert>
#include <iostream>
#include <string>

#include "../header/Enemy.hpp"

Difficulty::Difficulty() : diffi_level(-1) {}

Difficulty::~Difficulty() {
  for (auto& enemy : allEnemies) {
    delete enemy;
  }
  allEnemies.clear();
}

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
  switch (diffi_level) {
    case 1:
      setEasy();
      break;
    case 2:
      /* code */
      break;
    case 3:
      setHard();
      break;

    default:
      assert(0);
      break;
  }
}
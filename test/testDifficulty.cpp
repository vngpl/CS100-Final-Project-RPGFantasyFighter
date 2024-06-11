#include <gtest/gtest.h>

#include "../header/Diffi.hpp"
#include "../header/Enemy.hpp"

// Mock class for Enemy
class MockEnemy : public Enemy {
 public:
  MockEnemy(int level, int health, double attackStrength)
      : Enemy(health, attackStrength, level, "Normal") {}

  int getLevel() const {
    return level_;
  }
  int getHealth() const {
    return health_;
  }
  double getAttackStrength() const {
    return attackStrength_;
  }
  void setHealth(int health) {
    health_ = health;
  }
  void setAttackStrength(double attackStrength) {
    attackStrength_ = attackStrength;
  }

 private:
  int level_;
  int health_;
  double attackStrength_;
};

TEST(DifficultyTest, SetLevel) {
  Difficulty difficulty;
  difficulty.setLevel(2);
  EXPECT_TRUE(difficulty.levelSettled());
}

TEST(DifficultyTest, SetEasy) {
  Difficulty difficulty;
  MockEnemy enemy(10, 100, 20.0);
  std::vector<Enemy*> enemies = {&enemy};
  difficulty.setEnemies(enemies);
  difficulty.setLevel(1);

  EXPECT_EQ(enemy.getHealth(), 50);
  EXPECT_DOUBLE_EQ(enemy.getAttackStrength(), 10.0);
}

TEST(DifficultyTest, SetNormal) {
  Difficulty difficulty;
  MockEnemy enemy(10, 100, 20.0);
  std::vector<Enemy*> enemies = {&enemy};
  difficulty.setEnemies(enemies);
  difficulty.setLevel(2);

  EXPECT_EQ(enemy.getHealth(), 100);
  EXPECT_DOUBLE_EQ(enemy.getAttackStrength(), 20.0);
}

TEST(DifficultyTest, SetHard) {
  Difficulty difficulty;
  MockEnemy enemy(10, 100, 20.0);
  std::vector<Enemy*> enemies = {&enemy};
  difficulty.setEnemies(enemies);
  difficulty.setLevel(3);

  EXPECT_EQ(enemy.getHealth(), 150);
  EXPECT_DOUBLE_EQ(enemy.getAttackStrength(), 30.0);
}

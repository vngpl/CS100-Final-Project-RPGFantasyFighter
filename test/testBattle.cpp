#include <gtest/gtest.h>

#include "../header/Battle.hpp"

// Mock classes for Character and Enemy
class MockCharacter : public Character {
 public:
  explicit MockCharacter(int level, int health, double attackStrength)
      : Character(health, attackStrength, level, "Player") {}

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
  void useItem(int32_t itemIndex) {}

 private:
  int level_;
  int health_;
  double attackStrength_;
};

class MockEnemy : public Enemy {
 public:
  explicit MockEnemy(int level, int health, double attackStrength)
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

 private:
  int level_;
  int health_;
  double attackStrength_;
};

TEST(BattleTest, FightCharacterVsEnemy) {
  Battle battle;
  MockCharacter player(10, 100, 20.0);
  MockEnemy enemy(5, 50, 10.0);

  bool playerDead = battle.fight(&player, &enemy);

  EXPECT_FALSE(playerDead);
  EXPECT_GT(player.getHealth(), 0);
  EXPECT_EQ(enemy.getHealth(), 0);
}

TEST(BattleTest, FightEnemyVsCharacter) {
  Battle battle;
  MockCharacter player(5, 50, 10.0);
  MockEnemy enemy(10, 100, 20.0);

  bool playerDead = battle.fight(&player, &enemy);

  EXPECT_TRUE(playerDead);
  EXPECT_EQ(player.getHealth(), 0);
  EXPECT_GT(enemy.getHealth(), 0);
}

TEST(BattleTest, UseItem) {
  Battle battle;
  MockCharacter player(10, 50, 20.0);

  int initialHealth = player.getHealth();
  battle.use_item(&player, 0);  // Assuming itemIndex 0 heals the player

  EXPECT_GT(player.getHealth(), initialHealth);
}
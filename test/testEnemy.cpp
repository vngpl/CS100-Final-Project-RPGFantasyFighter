#include <gtest/gtest.h>
#include "../header/Enemy.hpp"

TEST(EnemyTest, DefaultConstructor) {
    Enemy enemy;
    EXPECT_EQ(enemy.getHealth(), 100);
    EXPECT_EQ(enemy.getAttackStrength(), 50.0);
    EXPECT_EQ(enemy.getLevel(), 5);
    EXPECT_EQ(enemy.getType(), "Normal");
}

TEST(EnemyTest, ParameterizedConstructor) {
    Enemy enemy(150, 75.5, 10, "Boss");
    EXPECT_EQ(enemy.getHealth(), 150);
    EXPECT_EQ(enemy.getAttackStrength(), 75.5);
    EXPECT_EQ(enemy.getLevel(), 10);
    EXPECT_EQ(enemy.getType(), "Boss");
}

TEST(EnemyTest, Setters) {
    Enemy enemy;
    enemy.setHealth(250);
    enemy.setAttackStrength(85.0);
    enemy.setLevel(12);
    EXPECT_EQ(enemy.getHealth(), 250);
    EXPECT_EQ(enemy.getAttackStrength(), 85.0);
    EXPECT_EQ(enemy.getLevel(), 12);
}

TEST(EnemyTest, GetType) {
    Enemy enemy(100, 100, 1, "MONSTER");
    EXPECT_EQ(enemy.getType(), "MONSTER");
}

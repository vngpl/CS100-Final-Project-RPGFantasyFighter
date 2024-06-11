#include <gtest/gtest.h>

#include "../header/Character.hpp"

TEST(CharacterTest, HealthTest) {
  Character testCharacter(50, 100, 5, "TEST CHARACTER");
  EXPECT_EQ(testCharacter.getHealth(), 50);
}

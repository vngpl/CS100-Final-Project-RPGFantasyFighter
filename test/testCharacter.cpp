#include <gtest/gtest.h>
#include "../header/Character.hpp"

TEST(CharacterTest, HealthTest) {
    Character testCharacter(50, 100, 5, "TEST CHARACTER");
    EXPECT_EQ(testCharacter.getHealth(), 50);
}

TEST(CharacterTest, LevelTest) {
    Character testCharacter(100, 100, 5, "TEST CHARACTER");
    EXPECT_EQ(testCharacter.getLevel(), 5);
}

TEST(CharacterTest, AddItemTest) {
    Character testCharacter(100, 100, 1, "TEST CHARACTER");
    testCharacter.addItem(new Item("SWORD", 20));

    const std::vector<Item*>& inventory = testCharacter.getInventoryItems();
    bool itemExists = (inventory.at(0) != nullptr);

    EXPECT_TRUE(itemExists);
}

TEST(CharacterTest, UpdateMonsterSlainCountTest) {
    Character testCharacter(100, 100, 5, "TEST CHARACTER");
    character.updateMonsterSlainCount();
    EXPECT_EQ(character.getMonstersSlain(), 1);
}

TEST(CharacterTest, UseItemTest) {
    Character testCharacter(100, 100, 5, "TEST CHARACTER");
    Item* item = new Item("SWORD", 20);
    testCharacter.addItem(item);
    testCharacter.useItem(0);

    EXPECT_FALSE(testCharacter.hasWeapon());
}

TEST(CharacterTest, DeathTest) {
    Character testCharacter(100, 100, 5, "TEST CHARACTER");
    testCharacter.setHealth(0);
    EXPECT_TRUE(testCharacter.isDead());
}
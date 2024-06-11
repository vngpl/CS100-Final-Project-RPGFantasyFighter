#include <gtest/gtest.h>

#include <ctime>

#include "../header/Assassin.hpp"
#include "../header/Item.hpp"

// Unit tests for items, inventory, and shop generate item

// Test for getStrength function
TEST(ItemTest, getStrength) {
  Sword* sword = new Sword();
  EXPECT_EQ(sword->getStrength(), 30);
  delete sword;
}

// Test for getCost function
TEST(ItemTest, getCost) {
  Sword* sword = new Sword();
  EXPECT_EQ(sword->getCost(), 1);
  delete sword;
}

// Test for getType function
TEST(ItemTest, getType) {
  Sword* sword = new Sword();
  EXPECT_EQ(sword->getType(), "SWORD");
  delete sword;
}

// Test for setStrength function
TEST(ItemTest, setStrength) {
  Dagger* dagger = new Dagger();
  dagger->setStrength(40);
  EXPECT_EQ(dagger->getStrength(), 40);
  delete dagger;
}

// Test for setCost function
TEST(ItemTest, setCost) {
  Dagger* dagger = new Dagger();
  dagger->setCost(5);
  EXPECT_EQ(dagger->getCost(), 5);
  delete dagger;
}

// Test for inventoryIsEmpty
TEST(CharacterTest, inventoryIsEmpty) {
  Assassin* character = new Assassin();
  Wand* wand = new Wand();
  character->addItem(wand);
  EXPECT_FALSE(character->inventoryIsEmpty());
  delete wand;
  delete character;
}

// Test for hasWeapon
TEST(CharacterTest, hasWeapon) {
  Assassin* character = new Assassin();
  Wand* wand = new Wand();
  character->addItem(wand);
  EXPECT_TRUE(character->hasWeapon());
  delete wand;
  delete character;
}

// Test for hasPotion
TEST(CharacterTest, hasPotion) {
  Assassin* character = new Assassin();
  HealthPotion* potion = new HealthPotion();
  character->addItem(potion);
  EXPECT_TRUE(character->hasPotion());
  delete potion;
  delete character;
}

// Test for addItem
TEST(CharacterTest, addItem) {
  Assassin* character = new Assassin();
  Sword* sword = new Sword();
  character->addItem(sword);
  ASSERT_EQ(character->getInventoryItems().at(0)->getType(), "SWORD");
  delete sword;
  delete character;
}

// Test for useItem
TEST(CharacterTest, UseItem) {
  Assassin* character = new Assassin();
  AttackPotion* potion = new AttackPotion();
  character->addItem(potion);
  character->useItem(0);
  ASSERT_EQ(character->getInventoryItems().at(0), nullptr);
  delete potion;
  delete character;
}

// Test for generateRandomItem function
TEST(ItemTest, GenerateRandomItem) {
  srand(
      static_cast<unsigned int>(time(0)));  // Seed the random number generator
  Item* randItem = Item::generateRandomItem();
  ASSERT_NE(randItem, nullptr);
  delete randItem;
}
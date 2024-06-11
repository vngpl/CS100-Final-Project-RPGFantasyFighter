#include "../header/Character.hpp"
#include "../header/Item.hpp"
#include "gtest/gtest.h"

//Unit tests for items, inventory, and shop generate item 

//Test for getStrength function
TEST(ItemTest, getStrength){
    Sword sword; 
    EXPECT_EQ(sword.getStrength(), 30);
}

//Test for getCost function
TEST(ItemTest, getCost){
    Sword sword; 
    EXPECT_EQ(sword.getCost(), 1);
}

//Test for getType function
TEST(Itemtest, getType){
    Sword sword;
    EXPECT_EQ(sword.getType(), "SWORD");
}



//Test for setStrength function
TEST(ItemTest, setStrength){
    Dagger dagger;
    dagger.setStrength(40);
    EXPECT_EQ(dagger.getStrength(), 40);
}

//Test for setCost function
TEST(ItemTest, setCost){
    Dagger dagger;
    dagger.setCost(5);
    EXPECT_EQ(dagger.getCost(), 5);
}



//Test for inventoryIsEmpty
TEST(CharacterTest, inventoryIsEmpty){
    Character* character; 
    Wand wand; 
    character->addItem(wand);
    EXPECT_FALSE(character->inventoryIsEmpty());
}

//Test for hasWeapon
TEST(CharacterTest, hasWeapon){
    Wand wand; 
    character->addItem(wand);
    EXPECT_TRUE(character->hasWeapon());
}

//Test for hasPotion
TEST(CharacterTest, hasPotion){
    HealthPotion potion; 
    character->addItem(potion);
    EXPECT_TRUE(character->hasPotion());
}

//Test for addItem 
TEST(CharacterTest, addItem){
    Character* character;
    Sword sword; 
    
    character.addItem(sword);
    
    ASSERT_EQ(character.getInventoryItems().at(0)->getType(), "SWORD");
}

//Test for useItem
TEST(CharacterTest, UseItem) {
    Character* character;
    AttackPotion* potion;

    character.addItem(potion);
    character.useItem(1); 

    ASSERT_EQ(character.getInventoryItems().at(1), nullptr);
}


//Test for generateRandomItem function
TEST(ItemTest, GenerateRandomItem){
    srand(time(0)); 
    Item* randItem = Item::generateRandomItem();
    ASSERT_NE(randItem, nullptr); 
}

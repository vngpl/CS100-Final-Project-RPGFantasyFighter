#include "../header/Assassin.hpp"
#include "../header/Battle.hpp"
// #include "../header/Display.hpp"
#include "../header/Item.hpp"
#include "../header/Monster.hpp"
#include "../header/Warrior.hpp"
#include "../header/Wizard.hpp"
#include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/EXP.hpp"
#include "../header/Coins.hpp"
#include "gtest/gtest.h"

// TEST(gettersCHAR, getCoins) {
//     Coins *aCoins = new Coins();
//     aCoins->addCoinsOnMONSERdeath();
//     EXPECT_EQ(aCharacter->getCoins(), 0.0);
// }

using namespace std;


TEST(gainExperience, levelUp) {
    std::unique_ptr<Enemy> enemy = std::make_unique<Monster>();
    std::unique_ptr<Character> aCharacter = std::make_unique<Assassin>();
    std::unique_ptr<Experience> charExperience = std::make_unique<Experience>(
                    aCharacter->getLevel(), aCharacter->getExperience(), aCharacter.get(), enemy.get());

    // Ensure initial experience is 0
    EXPECT_EQ(aCharacter->getExperience(), 0);

    // Simulate defeating the enemy
    enemy->setHealth(0);
    aCharacter->setExperience(charExperience->gainExperience(enemy->getHealth()));

    bool leveledUp = charExperience->updateLevel();
    EXPECT_TRUE(leveledUp);

    aCharacter->setNextExperience(charExperience->getNextEXP());

    // Check the character has leveled up correctly
    EXPECT_EQ(aCharacter->getLevel(), 6);
    EXPECT_EQ(aCharacter->getExperience(), 100); // Example value
    EXPECT_EQ(aCharacter->getNextExperience(), 187.5); // Example value for next level
}


TEST(gainExperience, gainedEXP) {
    std::unique_ptr<Enemy> enemy = std::make_unique<Monster>();
    std::unique_ptr<Character> aCharacter1 = std::make_unique<Warrior>();
    std::unique_ptr<Experience> charExperience = std::make_unique<Experience>(
                    aCharacter1->getLevel(), aCharacter1->getExperience(), aCharacter1.get(), enemy.get());

    // Ensure initial experience is 0
    aCharacter1->setLevel(5);
    EXPECT_EQ(aCharacter1->getExperience(), 0);

    // Simulate defeating the enemy
    enemy->setHealth(0);

    aCharacter1->setNextExperience(charExperience->getNextEXP());
    aCharacter1->setExperience(charExperience->gainExperience(enemy->getHealth()));

    bool leveledUp = charExperience->updateLevel();
    EXPECT_TRUE(leveledUp);

    aCharacter1->setNextExperience(charExperience->getNextEXP());

    EXPECT_EQ(aCharacter1->getExperience(), 100); // Example value
    EXPECT_EQ(aCharacter1->getNextExperience(), 187.5); // Example value for next level
}

TEST(gainExperience, pointAssign) {
    std::unique_ptr<Enemy> enemy = std::make_unique<Monster>();
    std::unique_ptr<Character> aCharacter = std::make_unique<Assassin>();
    std::unique_ptr<Experience> charExperience = std::make_unique<Experience>(
                    aCharacter->getLevel(), aCharacter->getExperience(), aCharacter.get(), enemy.get());


     // Ensure initial experience is 0
    EXPECT_EQ(aCharacter->getExperience(), 0);

    // Simulate defeating the enemy
    enemy->setHealth(0);
    aCharacter->setNextExperience(charExperience->getNextEXP());
    aCharacter->setExperience(charExperience->gainExperience(enemy->getHealth()));

    bool leveledUp = charExperience->updateLevel();
    EXPECT_TRUE(leveledUp);

    aCharacter->setExperience(charExperience->gainExperience(enemy->getHealth()));
    aCharacter->setNextExperience(charExperience->getNextEXP());

    int inputUser = 1;
    
    charExperience->pointAssign(inputUser);

    EXPECT_EQ(aCharacter->getHealth(), 100); //Should be 90+10 since 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




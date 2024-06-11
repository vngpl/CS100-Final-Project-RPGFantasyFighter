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

using namespace std;

TEST(addCoinsOnMONSERdeath, getrandCOINS) {
    std::unique_ptr<Coins> coins = nullptr;
    std::unique_ptr<Character> aCharacter = std::make_unique<Assassin>();
    std::unique_ptr<Enemy> enemy = std::make_unique<Monster>();

    coins = std::make_unique<Coins>(1, 10, aCharacter.get());

    enemy->setHealth(0);
    coins->addCoinsOnMONSERdeath(enemy->getHealth());

    EXPECT_GE(coins->getAmountCoins(), 1); // Check if coins generated is greater than or equal to 1
    EXPECT_LE(coins->getAmountCoins(), 10); // Check if coins generated is less than or equal to 10
}

TEST(addCoinsOnMONSERdeath, get0COINS) {
    std::unique_ptr<Coins> coins = nullptr;
    std::unique_ptr<Character> aCharacter = std::make_unique<Assassin>();
    std::unique_ptr<Enemy> enemy = std::make_unique<Monster>();

    coins = std::make_unique<Coins>(1, 10, aCharacter.get());

    EXPECT_EQ(coins->getAmountCoins(), 0); //RANDOM SO SOMETIMES WORKS SOMETIMES FAILS
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

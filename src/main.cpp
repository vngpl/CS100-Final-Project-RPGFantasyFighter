#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include "../header/init.hpp"

int main() {
    // Using smart pointers for automatic memory management
    std::unique_ptr<Character> player = nullptr;
    std::unique_ptr<Experience> charExperience = nullptr;
    std::unique_ptr<Coins> coins = nullptr;

    // Enemy list
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.reserve(N_ENEMY);

    Difficulty diffi;

    Display::printIntro();

    char option = getInput123();
    diffi.setLevel(static_cast<int32_t>(option - '0'));

    Display::printCharacterCreation();

    switch (getInput123()) {
        case '1':
            player = std::make_unique<Assassin>();
            break;
        case '2':
            player = std::make_unique<Warrior>();
            break;
        case '3':
            player = std::make_unique<Wizard>();
            break;
    }

    int32_t id = 0;
    while (!player->isDead()) {
        ++id;
        Display::printCharacterInformation(player.get());

        if (id <= 2) {
            for (size_t i = 0; i < N_ENEMY; ++i) {
                enemies.push_back(std::make_unique<Enemy>());
            }
        } else if (id <= 4) {
            for (size_t i = 0; i < N_ENEMY; ++i) {
                enemies.push_back(std::make_unique<Monster>());
            }
        } else {
            Display::printWinning();
            break;
        }

        Battle battle;
        int32_t ene_id = 0;
        for (const auto& enemy : enemies) {
            bool is_valid = false;
            bool ran_away = false; // Flag to check if the player ran away
            Display::printEnemy(++ene_id);
            while (!is_valid) {
                Display::printCharacterInformation(player.get());
                Display::printMONSTERInformation(enemy.get());
                Display::printBattleOptions();
                switch (getInput123()) {
                    case '1': {
                        bool player_dead = battle.fight(player.get(), enemy.get());
                        if (player_dead) {
                            Display::printGameOver();
                            return 0;
                        } else {
                            Display::printWinning();
                            enemy->setHealth(0);
                            player->updateMonsterSlainCount();
                        }
                        is_valid = true;
                        break;
                    }
                    case '2': {
                        if (player->inventoryIsEmpty()) {
                            Display::printInventoryIsEmpty(player.get());
                            break;
                        }
                        Display::printInventoryItems(player.get());
                        Display::printItemOptions(player.get());
                        if (player->hasWeapon() && player->hasPotion()) {
                            switch (getInputNWP()) {
                                case 'N':
                                    break;
                                case 'W':
                                    if (player->getInventoryItems().at(0)->getType() == "SWORD") {
                                        Display::printUseSword();
                                    } else if (player->getInventoryItems().at(0)->getType() == "DAGGER") {
                                        Display::printUseDagger();
                                    } else {
                                        Display::printUseWand();
                                    }
                                    player->useItem(0);
                                    break;
                                case 'P':
                                    if (player->getInventoryItems().at(1)->getType() == "HEALTH_POTION") {
                                        Display::printUseHealthPotion();
                                    } else {
                                        Display::printUseAttackPotion();
                                    }
                                    player->useItem(1);
                                    break;
                            }
                        } else if (player->hasPotion()) {
                            switch (getInputYN()) {
                                case 'N':
                                    break;
                                case 'Y':
                                    if (player->getInventoryItems().at(1)->getType() == "HEALTH_POTION") {
                                        Display::printUseHealthPotion();
                                    } else {
                                        Display::printUseAttackPotion();
                                    }
                                    player->useItem(1);
                                    break;
                            }
                        } else {
                            switch (getInputYN()) {
                                case 'N':
                                    break;
                                case 'Y':
                                    if (player->getInventoryItems().at(0)->getType() == "SWORD") {
                                        Display::printUseSword();
                                    } else if (player->getInventoryItems().at(0)->getType() == "DAGGER") {
                                        Display::printUseDagger();
                                    } else {
                                        Display::printUseWand();
                                    }
                                    player->useItem(0);
                                    break;
                            }
                        }
                        break;
                    }
                    case '3':
                        is_valid = true;
                        ran_away = true; // Mark that the player ran away
                        break;
                    default:
                        assert(0);
                        break;
                }
            }

            // Only process experience, level up, coins, and shop if the player did not run away
            if (!ran_away) {
                // Give EXP for winning
                charExperience = std::make_unique<Experience>(
                    player->getLevel(), player->getExperience(), player.get(), enemy.get());
                player->setExperience(charExperience->gainExperience());
                player->setNextExperience(charExperience->getNextEXP());
                Display::printExperience(player.get());

                // Check if they leveled up
                bool levelup = charExperience->updateLevel();
                if (levelup) {
                    Display::printStatAllocation(player.get());
                    switch (getInput123()) {
                        case '1':
                            Display::printHealth(player.get());
                            charExperience->pointAssign(1);
                            Display::printNEWHealth(player.get());
                            break;
                        case '2':
                            Display::printAttackStrength(player.get());
                            charExperience->pointAssign(2);
                            Display::printNEWAttackStrength(player.get());
                            break;
                    }
                } else {
                    Display::printLevelcount(player.get());
                }

                // Give Coins for winning
                coins = std::make_unique<Coins>(1, 10, player.get());
                coins->addCoinsOnMONSERdeath(enemy->getHealth());
                player->setCoins(coins->getAmountCoins());
                Display::printCoins(player.get());

                if (enemy->getHealth() <= 0) {
                    Item* randItem = randItem->generateRandomItem();
                    if (randItem->getType() == "SWORD") {
                        Display::printShopGenerateSword();
                    } else if (randItem->getType() == "DAGGER") {
                        Display::printShopGenerateDagger();
                    } else if (randItem->getType() == "WAND") {
                        Display::printShopGenerateWand();
                    } else if (randItem->getType() == "HEALTH_POTION") {
                        Display::printShopGenerateHealthPotion();
                    } else {
                        Display::printShopGenerateAttackPotion();
                    }
                    switch (getInputYN()) {
                        case 'N':
                            delete randItem;
                            break;
                        case 'Y':
                            if (player->getCoins() >= randItem->getCost()) {
                                player->addItem(randItem);
                                Display::printItemBuyPass();
                                player->setCoins(player->getCoins() - randItem->getCost());
                            } else {
                                Display::printItemBuyFail();
                                delete randItem;
                            }
                    }
                }

                Display::printAttackStrengthMONSTER(enemy.get());
                Display::printHealthMONSTER(enemy.get());
                Display::printLevelMONSTER(enemy.get());
                Display::printInventoryItems(player.get());
            }
        }
    }

    return 0;
}

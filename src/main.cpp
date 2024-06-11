#include <cassert>
#include <iostream>
#include <vector>

#include "../header/init.hpp"

int main() {
  // player
  Character* player = nullptr;
  Experience* charExperience = nullptr;
  Coins* coins = nullptr;

  // enemy list
  std::vector<Enemy*> enemies;
  enemies.reserve(N_ENEMY);

  Difficulty diffi;

  Display::printIntro();

  char option = getInput123();
  diffi.setLevel(static_cast<int32_t>(option - '0'));

  Display::printCharacterCreation();

  switch (getInput123()) {
    case '1':
      player = new Assassin();
      break;
    case '2':
      player = new Warrior();
      break;
    case '3':
      player = new Wizard();
      break;
  }
  // 3. Quit
  //   {
  //     Display::printQuit(player);
  //     delete player;
  //     return 0;
  //   }

  // Main game
  diffi.setEnemies(enemies);
  int32_t id = 0;
  while (!player->isDead()) {
    ++id;
    Display::printCharacterInformation(player);

    if (id <= 2) {
      for (size_t i = 0; i < N_ENEMY; ++i) {
        enemies.push_back(new Enemy());
      }
    } else if (id <= 4) {
      for (size_t i = 0; i < N_ENEMY; ++i) {
        enemies.push_back(new Monster());
      }
    } else {
      Display::printWinning();
      break;
    }

    // Start battle
    Battle battle;
    int32_t ene_id = 0;
    for (const auto& enemy : enemies) {
      bool is_valid = false;
      Display::printEnemy(++ene_id);
      while (!is_valid) {
        Display::printCharacterInformation(player);
        Display::printMONSTERInformation(enemy);
        Display::printBattleOptions();
        switch (getInput123()) {
          case '1':
            /* fight */
            {
              bool player_dead = battle.fight(player, enemy);
              if (player_dead) {
                Display::printGameOver();
                delete player;
                for (auto& e : enemies) {
                  delete e;
                }
                enemies.clear();
                return 0;
              } else {
                Display::printWinning();
                enemy->setHealth(0);
                player->updateMonsterSlainCount();
              }
              is_valid = true;
              break;
            }
          case '2':
            /* use item */
            {
              if (player->inventoryIsEmpty()) {
                Display::printInventoryIsEmpty();
                break;
              }
              Display::printInventoryItems(player);
              Display::printItemOptions(player);
              if (player->hasWeapon() && player->hasPotion()) {
                switch (getInputNWP()) {
                  case 'N':
                    break;
                  case 'W':
                    if (player->getInventoryItems().at(0)->getType() ==
                        "SWORD") {
                      Display::printUseSword();
                    } else if (player->getInventoryItems().at(0)->getType() ==
                               "DAGGER") {
                      Display::printUseDagger();
                    } else {
                      Display::printUseWand();
                    }
                    player->useItem(0);
                    break;
                  case 'P':
                    if (player->getInventoryItems().at(1)->getType() ==
                        "HEALTH_POTION") {
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
                    if (player->getInventoryItems().at(1)->getType() ==
                        "HEALTH_POTION") {
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
                    if (player->getInventoryItems().at(0)->getType() ==
                        "SWORD") {
                      Display::printUseSword();
                    } else if (player->getInventoryItems().at(0)->getType() ==
                               "DAGGER") {
                      Display::printUseDagger();
                    } else {
                      Display::printUseWand();
                    }
                    player->useItem(0);
                    break;
                }
                break;
              }
              case '3':
                /* run */
                // TODO: Exit the game
                is_valid = true;
                break;
              default:
                assert(0);
                break;
            }
        }
      }

      // Give EXP for winning
      delete charExperience;
      charExperience = new Experience(player->getLevel(),
                                      player->getExperience(), player, enemy);
      player->setExperience(charExperience->gainExperience());
      player->setNextExperience(charExperience->getNextEXP());
      Display::printExperience(player);

      // Check if they leveled up
      bool levelup = charExperience->updateLevel();
      // If user leveled up tell them
      if (levelup) {
        // TODO: display level up
        // Display::printLEVELUP(player);

        // Ask if user wants to allocate stats
        //  Display::printAttackStrength(player); //old attack
        Display::printStatAllocation();
        switch (getInput123()) {
          case '1':
            /* Enhancing health */
            {
              Display::printHealth(player);
              charExperience->pointAssign(1);
              Display::printNEWHealth(player);
            }
            break;
          case '2':
            /* Intensive attack */
            {
              Display::printAttackStrength(player);
              charExperience->pointAssign(2);
              Display::printNEWAttackStrength(player);
              break;
            }
          default:
            break;
        }
      } else {
        // Just show how much needed for next level
        Display::printLevelcount(player);
      }

      // Give Coins for winning
      delete coins;
      coins = new Coins(1, 10, player);
      coins->addCoinsOnMONSERdeath(enemy->getHealth());
      player->setCoins(coins->getAmountCoins());
      Display::printCoins(player);

      // User defeats Monster, 'shop' generates a random item that can be
      // purchased by user Change Monster to whatever we call our created
      // monster
      if (enemy->getHealth() <= 0) {
        // Some display function outputting something like "You defeated
        // monster"

        Item* randItem = Item::generateRandomItem();

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
              delete randItem;  // delete item if it can't be bought
            }
        }
      }

      // SHOW STATS THAT CHANGE MONSTER CLASS
      Display::printAttackStrengthMONSTER(enemy);
      Display::printHealthMONSTER(enemy);
      Display::printLevelMONSTER(enemy);

      Display::printInventoryItems(player);
    }

    // Delete all enemies after each round of battle
    for (auto& e : enemies) {
      delete e;
    }
    enemies.clear();
  }

  // Free remaining resources
  delete player;
  delete coins;
  delete charExperience;

  return 0;
}
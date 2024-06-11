#include <cassert>
#include <iostream>

#include "../header/init.hpp"

// bool invalidOption(const std::string&, const int32_t);
// const std::string requestInput(const int32_t num);
const char getInput123();
const char getInputYN();
const char getInputNWP();
constexpr size_t N_ENEMY = 3;

int main() {
  // player
  Character* player = nullptr;

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
  while (!player->isDead()) {
    Display::printCharacterInformation(player);

    for (size_t i = 0; i < N_ENEMY; ++i) {
      // TODO: randomize new enemies
      enemies.push_back(new Enemy());
    }

    // Start battle
    Battle battle;
		int32_t id = 0;
    for (const auto& enemy : enemies) {
      bool is_valid = false;
			Display::printEnemy(++id);
      while (!is_valid) {
        Display::printBattleOptions();
        switch (getInput123()) {
          case '1':
            /* fight */
            {
              bool player_dead = battle.fight(player, enemy);
              if (player_dead) {
                Display::printGameOver();
              } else {
                Display::printWinning();
              }
              is_valid = true;
              break;
            }
          case '2':
            /* use item */
            {
              if (player->inventoryIsEmpty()) {
                Display::printInventoryIsEmpty(player);
                break;
              }
              Display::printInventoryItems(player);
              Display::printItemOptions(player);
              if (player->hasWeapon()) {
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
                    // player->useItem(0);
										battle.use_item(player, 0);
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
                    // player->useItem(1);
										battle.use_item(player, 1);
                    break;
                }
              } else {
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
                    // player->useItem(0);
										battle.use_item(player, 0);
                    break;
                  case 'P':
                    if (player->getInventoryItems().at(1)->getType() == "HEALTH_POTION") {
                      Display::printUseHealthPotion();
                    } else {
                      Display::printUseAttackPotion();
                    }
                    // player->useItem(1);
										battle.use_item(player, 1);
                    break;
                }
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

      // Give EXP for winning
      Experience* charExperience =
          new Experience(player->getLevel(), player->getExperience(), player, enemy);
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
        Display::printStatAllocation(player);
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
      Coins* coins = new Coins(1, 10);
      coins->addCoinsOnMONSERdeath(enemy->getHealth());
      player->setCoins(coins->getAmountCoins());
      Display::printCoins(player);

      Display::printNewline();

      // SHOW STATS THAT CHANGE MONSTER CLASS
      Display::printAttackStrengthMONSTER(enemy);
      Display::printHealthMONSTER(enemy);
      Display::printLevelMONSTER(enemy);

      Display::printInventoryItems(player);
    }
  }
  Display::printNewline();

  // Free
  delete player;
  for (auto& enemy : enemies) {
    delete enemy;
  }
  // delete enemy;
  // delete monster;

  return 0;
}

const char getInput123() {
	char option;
  do {
    std::cin >> option;
    if (option != '1' && option != '2' && option != '3') {
      Display::printInvalidInput();
    }
  } while (option != '1' && option != '2' && option != '3');
  return option;
}

const char getInputYN() {
	char option;
  do {
    std::cin >> option;
    if (option != 'Y' && option != 'N') {
      Display::printInvalidInput();
    }
  } while (option != 'Y' && option != 'N');
  return option;
}

const char getInputNWP() {
	char option;
  do {
    std::cin >> option;
    if (option != 'N' && option != 'W' && option != 'P') {
      Display::printInvalidInput();
    }
  } while (option != 'N' && option != 'W' && option != 'P');
  return option;
}
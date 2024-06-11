#include <cassert>
#include <iostream>

#include "../header/init.hpp"

bool invalidOption(const std::string&, const int32_t);
const std::string requestInput(const int32_t num);
constexpr size_t N_ENEMY = 3;

int main() {
  // player
  Character* player = nullptr;

  // enemy list
  std::vector<Enemy*> enemies;
  enemies.reserve(N_ENEMY);

  Difficulty diffi;

  Display::printIntro();
  // WELCOME TO FANTASY FIGHTER I
  // 1. Character Creation
  // 2. Settings
  // 3. Quit
  std::string option = "";
  while (true) {
    option = requestInput(3);
    switch (std::stoi(option)) {
      // 1. Character Creation
      case 1:
        // CHOOSE YOUR FIGHTER TYPE:
        // 1. Assassin (+20 ATK, -10 HP)
        // 2. Warrior (+0 ATK, +25 HP)
        // 3. Wizard (+0 ATK, +0 HP)
        {
          Display::printCharacterCreation();
          option = requestInput(3);
          switch (std::stoi(option)) {
            // 1. Assassin (+20 ATK, -10 HP)
            case 1:
              player = new Assassin();
              break;
            // 2. Warrior (+0 ATK, +25 HP)
            case 2:
              player = new Warrior();
              break;
            // 3. Wizard (+0 ATK, +0 HP)
            case 3:
              player = new Wizard();
              break;
            default:
              break;
          }
          break;
        }
      // 2. Settings
      case 2:
        // CHOOSE GAME DIFFICULTY:
        // 1. Easy
        // 2. Medium
        // 3. Hard
        {
          Display::printSettings();
          option = requestInput(3);
          diffi.setLevel(std::stoi(option));
          break;
        }
      // 3. Quit
      case 3:
        // Thank you for playing!
        {
          Display::printQuit(player);
          delete player;
          return 0;
        }
    }
    if (!player || !diffi.levelSettled()) {
      Display::printIntroAgain();
    } else {
      break;
    }
  }

  // Main game
  while (!player->isDead()) {
    Display::printCharacterInformation(player);

    for (size_t i = 0; i < N_ENEMY; ++i) {
      // TODO: randomize new enemies
      enemies.push_back(new Enemy());
    }

    // Start battle
    Battle battle;
    for (const auto& enemy : enemies) {
      bool is_valid = false;
      while (!is_valid) {
        Display::printBattleOptions();
        option = requestInput(3);
        switch (std::stoi(option)) {
          case 1:
            /* fight */
            {
              bool player_dead = battle.fight(player, enemy, option);
              if (player_dead) {
                Display::printGameOver();
              } else {
                // TODO: Winning the round display
                std::cerr << "You win this game!" << std::endl;
              }
              is_valid = true;
              break;
            }
          case 2:
            /* use item */
            {
              is_valid = Display::printItemOptions(player);
              if (is_valid) {
                option = requestInput(2);
                battle.use_item(player, option);
              }
            }
          case 3:
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
        int numInput = std::stoi(requestInput(3));
        switch (numInput) {
          case 1:
            /* Enhancing health */
            {
              Display::printHealth(player);
              charExperience->pointAssign(numInput);
              Display::printNEWHealth(player);
            }
            break;
          case 2:
            /* Intensive attack */
            {
              Display::printAttackStrength(player);
              charExperience->pointAssign(numInput);
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

bool invalidOption(const std::string& option, const int32_t num) {
  for (int i = 1; i <= num; ++i) {
    if (std::stoi(option) == i) {
      return false;
    }
  }
  return true;
}

const std::string requestInput(const int32_t num) {
  std::string option;
  std::cin >> option;
  while (invalidOption(option, num)) {
    Display::printNewline();
    Display::printInvalidInput();
    Display::printSelectOption();
    std::cin >> option;
  }
  Display::printNewline();
  return option;
}

//User selects number that corresponds to Item on the screen with Fight, Items, and Run 
//Change user's choice char to whatever our input variable is called
// std::cin >> x;

// if (x == 2){ //Change 2 to what our option for the Items screen is called 
// 	printInventoryItems();
// 	printItemOptions();

// 	if (character->InventoryIsEmpty()){
// 		//Break statement or loop back to Fight, Items, or Run Screen 
// 	}

// 	//User makes choice for weapon, potion, or if they have both 
// 	cin >> x;

// 	if (character->hasWeapon()){
// 		if (x == "Y"){
// 			if (inventory.at(0)->getType() == "SWORD"){
// 				printUseSword();
// 			}
// 			else if (inventory.at(0)->getType() == "DAGGER"){
// 				printUseDagger();
// 			}
// 			else{
// 				printUseWand();
// 			}

// 			character->useItem(inventory.at(0)) //Change to how to access character's inventory first item 
// 		}
// 		if (x == "N"){
// 			//Break statement or loop back to Fight, Items, or Run Screen 
// 		}
// 	}
// 	else if (character->hasPotion()){
// 		if (x == "Y"){
// 			if (inventory.at(1)->getType() == "HEALTH_POTION"){
// 				printUseHealthPotion();
// 			}
// 			else{
// 				printUseAttackPotion();
// 			}

// 			character->useItem(inventory.at(1)) //Change to how to access character's inventory second item 
// 		}
// 		if (x == "N"){
// 			//Break statement or loop back to Fight, Items, or Run Screen 
// 		}
// 	}
// 	//Character has both weapon and potion in inventory 
// 	else{
// 		if (x == "W"){
// 			if (inventory.at(0)->getType() == "SWORD"){
// 				printUseSword();
// 			}
// 			else if (inventory.at(0)->getType() == "DAGGER"){
// 				printUseDagger();
// 			}
// 			else{
// 				printUseWand();
// 			}

// 			character->useItem(inventory.at(0)) //Change to how to access character's inventory first item 
// 		}
// 		if (x == "P"){
// 			if (inventory.at(1)->getType() == "HEALTH_POTION"){
// 				printUseHealthPotion();
// 			}
// 			else{
// 				printUseAttackPotion();
// 			}

// 			character->useItem(inventory.at(1)) //Change to how to access character's inventory second item 
// 		}
// 		if (x == "N"){
// 			//Break statement or loop back to Fight, Items, or Run Screen 
// 		}
// 	}
// }

// //User defeats Monster, 'shop' generates a random item that can be purchased by user 
// //Change Monster to whatever we call our created monster 
// if (Monster->getHealth() <= 0){

// 	//Some display function outputting something like "You defeated monster"

// 	Item* randItem = nullptr;
// 	randItem = randItem->generateRandomItem(); 

// 	if (randItem->getType() == "SWORD"){
// 		printShopGenerateSword();
// 	}
// 	else if (randItem->getType() == "DAGGER"){
// 		printShopGenerateDagger();
// 	}
// 	else if (randItem->getType() == "WAND"){
// 		printShopGenerateWand();
// 	}
// 	else if (randItem->getType() == "HEALTH_POTION"){
// 		printShopGenerateHealthPotion();
// 	}
// 	else{
// 		printShopGenerateAttackPotion();
// 	}

// 	//The print statements above ask the user if they would like to buy the item generated (Y/N)
// 	//change user's choice char to whatever our input variable is called
// 	std::cin >> x; 

// 	if (x == "N"){
// 		//Display output of new level or monster OR loops back into screen with Fight, Items, and Run 
// 		//Break statement here? 
// 	}
// 	else if (x == "Y"){
// 		if (character->getCoins() >= randItem->getCost()){
// 			character->addItem(randItem);
// 			printItemBuyPass();
// 			character->setCoins(character->getCoins() - randItem->getCost());
// 		}
// 		else{
// 			printItemBuyFail();
// 			//User did not have enough coins to buy item, go to next level/monster 
// 		}
// 	}
// }


#include <iostream>
#include "../header/init.hpp"

bool invalid123(const char& option);
bool invalidYN(const char& option);
bool invalidNWP(const char& option);
const char& getInput(char& option);

int main() {
	Character* player = nullptr;
	char option;

    Display::printIntro();

    switch (getInput(option)) {
        case '1':
            Difficulty::setEasy();
            break;
        case '2':
            Difficulty::setNormal();
            break;
        case '3':
            Difficulty::setHard();
            break;
    }

    Display::printCharacterCreation();

    switch (getInput(option)) {
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

	player->addItem(new Sword());
	player->addItem(new HealthPotion());
	// if (player != nullptr) {
	// 	Display::printCharacterInformation(player);
	// }

	Display::printBattleOptions();

	switch (getInput(option)) {
        case '1':
            // finish
            break;
        case '2':
			if (player->inventoryIsEmpty()) {
				Display::printInventoryIsEmpty(player);
				break;
			}
			Display::printInventoryItems(player);
			Display::printItemOptions(player);
			if (character->hasWeapon()) {
				switch (getInput(option)) {
					case 'N':
						break;
					case 'Y':
						if (inventory.at(0)->getType() == "SWORD"){
							Display::printUseSword();
						}
						else if (inventory.at(0)->getType() == "DAGGER"){
							Display::printUseDagger();
						}
						else{
							Display::printUseWand();
						}
						character->useItem(inventory.at(0));
						break;
				}
			}
			else if (character->hasPotion()) {
				switch (getInput(option)) {
					case 'N':
						break;
					case 'Y':
						if (inventory.at(1)->getType() == "HEALTH_POTION"){
							Display::printUseHealthPotion();
						}
						else {
							Display::printUseAttackPotion();
						}
						character->useItem(inventory.at(1));
						break;
				}
			}
			else {
				switch (getInput(option)) {
					case 'N':
						break;
					case 'W':
						if (inventory.at(0)->getType() == "SWORD"){
							Display::printUseSword();
						}
						else if (inventory.at(0)->getType() == "DAGGER"){
							Display::printUseDagger();
						}
						else{
							Display::printUseWand();
						}
						character->useItem(inventory.at(0));
						break;
					case 'P':
						if (inventory.at(1)->getType() == "HEALTH_POTION"){
							Display::printUseHealthPotion();
						}
						else {
							Display::printUseAttackPotion();
						}
						character->useItem(inventory.at(1));
						break;
				}
			}
            break;
        case '3':
            player = new Wizard();
            break;
    }


	// Display::printInventoryItems(player);

	// Display::printQuit(player);
    // std::exit(EXIT_SUCCESS);

    // while (game.getInput() != 'Q') {
    //     Display::printBattleOptions();
	// 	game.getInput();
    // }


	// //Start battle with monster
	// Enemy* enemy = new Monster();
	// //FINSHED BATTLE
	// enemy->setHealth(-1000); //ded

	// //ADD BATTLE HERE before gainning coins, exp, shop, and levelup

	// //Give EXP for winning
	// Experience *charExperience = new Experience(player->getLevel(), player->getExperience(), player, enemy);
	// player->setExperience(charExperience->gainExperience());
	// player->setNextExperience(charExperience->getNextEXP());
	// Display::printExperience(player);

	// // Check if they leveled up
	// bool levelup = charExperience->updateLevel();
	// //If user leveled up tell them
	// if (levelup) {
	// 	Display::printLEVELUP(player);
	// 	//Ask if user wants to allocate stats
	// 	// Display::printAttackStrength(player); //old attack
	// 	Display::printStatAllocation(player);
	// 	int numInput = std::stoi(requestInput());
	// 	if (numInput == 1) {
	// 		Display::printHealth(player);
	// 		charExperience->pointAssign(numInput);
	// 		Display::printNEWHealth(player);
	// 	}
	// 	else if (numInput == 2) {
	// 		Display::printAttackStrength(player);
	// 		charExperience->pointAssign(numInput);
	// 		Display::printNEWAttackStrength(player);
	// 	}
	// 	else {
	// 		Display::printInvalidInput();
	// 	}
	// }
	// else {
	// 	//Just show how much needed for next level
	// 	Display::printLevelcount(player);
	// }

	// //Give Coins for winning
	// Coins* coins = new Coins(1,10);
	// coins->addCoinsOnMONSERdeath(enemy->getHealth());
	// player->setCoins(coins->getAmountCoins());
	// Display::printCoins(player);

	// Display::printNewline();

	// while (!player->isDead()) {
		// Display::printBattleOptions();
		// // Battle battle;

		// switch (requestInput(option)) {
		// 	case '1':
		// 		// finish
		// 		break;
		// 	case '2':
		// 		// finish
		// 		break;
		// 	case '3':
		// 		// finish
		// 		break;

		// }
	// }

	// Display::printCharacterInformation(player);


	// Display::printNewline();

	//SHOW STATS THAT CHANGE MONSTER CLASS
	// Display::printAttackStrengthMONSTER(enemy);
	// Display::printHealthMONSTER(enemy);
	// Display::printLevelMONSTER(enemy);

	// Display::printInventoryItems(player);

	delete player;
	player = nullptr;

	return 0;
}

// //User defeats Monster, 'shop' generates a random item that can be purchased by user
// //Change Monster to whatever we call our created monster
// if (Monster->getHealth() <= 0){

// 	//Some display function outputting something like "You defeated monster"

// 	Item* randItem = nullptr;
// 	randItem = randItem->generateRandomItem();

// 	if (randItem->getType() == "SWORD"){
// 		Display::printShopGenerateSword();
// 	}
// 	else if (randItem->getType() == "DAGGER"){
// 		Display::printShopGenerateDagger();
// 	}
// 	else if (randItem->getType() == "WAND"){
// 		Display::printShopGenerateWand();
// 	}
// 	else if (randItem->getType() == "HEALTH_POTION"){
// 		Display::printShopGenerateHealthPotion();
// 	}
// 	else{
// 		Display::printShopGenerateAttackPotion();
// 	}

// 	//The print statements above ask the user if they would like to buy the item generated (Y/N)
// 	//change user's choice char to whatever our input variable is called
// 	std::cin >> x;

// 	if (x == 'N'){
// 		//Display output of new level or monster OR loops back into screen with Fight, Items, and Run
// 		//Break statement here?
// 	}
// 	else if (x == 'Y'){
// 		if (character->getCoins() >= randItem->getCost()){
// 			character->addItem(randItem);
// 			Display::printItemBuyPass();
// 			character->setCoins(character->getCoins() - randItem->getCost());
// 		}
// 		else{
// 			Display::printItemBuyFail();
// 			//User did not have enough coins to buy item, go to next level/monster
// 		}
// 	}
// }

bool invalid123(const char& option) {
	return (option != '1' && option != '2' && option != '3');
}

bool invalidYN(const char& option) {
	return (option != 'Y' && option != 'N');
}

bool invalidNWP(const char& option) {
	return (option != 'N' && option != 'W' && option != 'P');
}

const char& getInput(char& option) {
	do {
        std::cin >> option;
        if (invalid123(option) || invalidYN(option) || invalidNWP(option)) {
            Display::printInvalidInput();
        }
    }
	while (invalid123(option) || invalidYN(option) || invalidNWP(option));
    return option;
}

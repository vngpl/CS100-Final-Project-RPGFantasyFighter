#include <iostream>

#include "../header/init.hpp"

bool invalidOption(const std::string&);
const std::string requestInput(/*const std::string&*/);

int main() {
	Character* player = nullptr;
	Enemy* enemy = nullptr;

  Display::printIntro();

	// WELCOME TO FANTASY FIGHTER I
	// 1. Character Creation
	// 2. Settings
	// 3. Quit
	std::string option = requestInput();
	switch (std::stoi(option)) {
		// 1. Character Creation
		case 1:
			// CHOOSE YOUR FIGHTER TYPE:
			// 1. Assassin (+20 ATK, -10 HP)
			// 2. Warrior (+0 ATK, +25 HP)
			// 3. Wizard (+0 ATK, +0 HP)
			Display::printCharacterCreation();
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
			}
			break;
		// 2. Settings
		case 2:
			// CHOOSE GAME DIFFICULTY:
			// 1. Easy
			// 2. Medium
			// 3. Hard
			Display::printSettings();
			switch (std::stoi(option)) {
				// 1. Easy
				case 1:
					Difficulty::setEasy();
					break;
        // 2. Medium
				case 2:
					Difficulty::setNormal();
					break;
				// 3. Hard
				case 3:
					Difficulty::setHard();
					break;
			}
			break;
		// 3. Quit
		case 3:
			// Thank you for playing!
			Display::printQuit(player);
			break;
	}

	// Display::printCharacterInformation(player);

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
	
	Display::printNewline();

	// while (!player->isDead()) {
		option = requestInput();
		Display::printBattleOptions();
		Battle battle;

		switch (std::stoi(option)) {
			case 1:
				// finish
				break;
			case 2:
				// finish
				break;
			case 3:
				// finish
				break;

		}
	// }

	// Display::printCharacterInformation(player);


	Display::printNewline();

	//SHOW STATS THAT CHANGE MONSTER CLASS
	Display::printAttackStrengthMONSTER(enemy);
	Display::printHealthMONSTER(enemy);
	Display::printLevelMONSTER(enemy);

	Display::printInventoryItems(player);

  // Randomly generate enemies
  std::vector<Monster*> monsters;
  for (int i = 0; i < 5; ++i) {
    monsters.push_back(new Monster());
  }
  std::vector<Enemy*> enemies(monsters.begin(), monsters.end());

  // Battle
  Battle battle;
	for (const auto& enemy : enemies) {
  	battle.fight(player, enemies);
	}

  // Free
  for (Monster* monster : monsters) {
    delete monster;
  }
  delete player;

  return 0;
}

bool invalidOption(const std::string& option) {
	return (option != "1" && option != "2" && option != "3");
}

const std::string requestInput(/*const std::string& option*/) {
	std::string option;
	std::cin >> option;
	while (invalidOption(option)) {
		Display::printNewline();
		Display::printInvalidInput();
		Display::printSelectOption();
		std::cin >> option;
	}
	Display::printNewline();
	return option;
}
#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string&);
const std::string& requestInput(const std::string&);

int main() {
	Character* player = nullptr;

	Enemy* enemy = nullptr;
	enemy = new Monster();
	player = new Assassin();
	// player->inventory->getItem(0);

	std::string option;


	Display::printIntro();

	switch (std::stoi(requestInput(option))) {
		case 1:
			Display::printCharacterCreation();
			switch (std::stoi(requestInput())) {
				case 1:
					player = new Assassin();
					break;
				case 2:
					player = new Warrior();
					break;
				case 3:
					player = new Wizard();
					break;
			}
			break;
		case 2:
			Display::printSettings();
			switch (std::stoi(requestInput())) {
				case 1:
					Difficulty::setEasy();
					break;
				case 2:
					Difficulty::setNormal();
					break;
				case 3:
					Difficulty::setHard();
					break;
			}
			break;
		case 3:
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

	//SHOW STATS THAT CHANGE MONSTER CLASS
	Display::printAttackStrengthMONSTER(enemy);
	Display::printHealthMONSTER(enemy);
	Display::printLevelMONSTER(enemy);


	Display::printInventoryItems(player);


	delete enemy;
	enemy = nullptr;

	delete player;
	player = nullptr;

	return 0;
}

bool invalidOption(const std::string& option) {
	return (option != "1" && option != "2" && option != "3");
}

const std::string& requestInput(const std::string& option) {
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
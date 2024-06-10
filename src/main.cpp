#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string&);
const char& requestInput(char&);

int main() {
	Character* player = nullptr;
	Enemy* enemy = nullptr;

	Display::printIntro();

	// WELCOME TO FANTASY FIGHTER I
	// 1. Character Creation
	// 2. Settings
	// 3. Quit
	char option = requestInput(option);
	switch (option) {
		// 1. Character Creation
		case '1':
			// CHOOSE YOUR FIGHTER TYPE:
			// 1. Assassin (+20 ATK, -10 HP)
			// 2. Warrior (+0 ATK, +25 HP)
			// 3. Wizard (+0 ATK, +0 HP)
			Display::printCharacterCreation();
			switch (option) {
				// 1. Assassin (+20 ATK, -10 HP)
				case '1':
					player = new Assassin();
					break;
				// 2. Warrior (+0 ATK, +25 HP)
				case '2':
					player = new Warrior();
					break;
				// 3. Wizard (+0 ATK, +0 HP)
				case '3':
					player = new Wizard();
					break;
			}
			break;
		// 2. Settings
		case '2':
			// CHOOSE GAME DIFFICULTY:
			// 1. Easy
			// 2. Medium
			// 3. Hard
			Display::printSettings();
			switch (option) {
				// 1. Easy
				case '1':
					Difficulty::setEasy();
					break;
        // 2. Medium
				case '2':
					Difficulty::setNormal();
					break;
				// 3. Hard
				case '3':
					Difficulty::setHard();
					break;
			}
			break;
		// 3. Quit
		case '3':
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
		option = requestInput(option);
		Display::printBattleOptions();
		Battle battle;

		switch (option) {
			case '1':
				// finish
				break;
			case '2':
				// finish
				break;
			case '3':
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

	delete player;
	player = nullptr;

	return 0;
}

bool invalidOption(const char& option) {
	return (option != '1' && option != '2' && option != '3');
}

const char& requestInput(char& option) {
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

//User selects number that corresponds to Item on the screen with Fight, Items, and Run 
//Change user's choice char to whatever our input variable is called
std::cin >> x;

if (x == 2){ //Change 2 to what our option for the Items screen is called 
	printInventoryItems();
	printItemOptions();

	if (character->InventoryIsEmpty()){
		//Break statement or loop back to Fight, Items, or Run Screen 
	}

	//User makes choice for weapon, potion, or if they have both 
	cin >> x;

	if (character->hasWeapon()){
		if (x == "Y"){
			if (inventory.at(0)->getType() == "SWORD"){
				printUseSword();
			}
			else if (inventory.at(0)->getType() == "DAGGER"){
				printUseDagger();
			}
			else{
				printUseWand();
			}

			character->useItem(inventory.at(0)) //Change to how to access character's inventory first item 
		}
		if (x == "N"){
			//Break statement or loop back to Fight, Items, or Run Screen 
		}
	}
	else if (character->hasPotion()){
		if (x == "Y"){
			if (inventory.at(1)->getType() == "HEALTH_POTION"){
				printUseHealthPotion();
			}
			else{
				printUseAttackPotion();
			}

			character->useItem(inventory.at(1)) //Change to how to access character's inventory second item 
		}
		if (x == "N"){
			//Break statement or loop back to Fight, Items, or Run Screen 
		}
	}
	//Character has both weapon and potion in inventory 
	else{
		if (x == "W"){
			if (inventory.at(0)->getType() == "SWORD"){
				printUseSword();
			}
			else if (inventory.at(0)->getType() == "DAGGER"){
				printUseDagger();
			}
			else{
				printUseWand();
			}

			character->useItem(inventory.at(0)) //Change to how to access character's inventory first item 
		}
		if (x == "P"){
			if (inventory.at(1)->getType() == "HEALTH_POTION"){
				printUseHealthPotion();
			}
			else{
				printUseAttackPotion();
			}

			character->useItem(inventory.at(1)) //Change to how to access character's inventory second item 
		}
		if (x == "N"){
			//Break statement or loop back to Fight, Items, or Run Screen 
		}
	}
}

//User defeats Monster, 'shop' generates a random item that can be purchased by user 
//Change Monster to whatever we call our created monster 
if (Monster->getHealth() <= 0){

	//Some display function outputting something like "You defeated monster"

	Item* randItem = nullptr;
	randItem = randItem->generateRandomItem(); 

	if (randItem->getType() == "SWORD"){
		printShopGenerateSword();
	}
	else if (randItem->getType() == "DAGGER"){
		printShopGenerateDagger();
	}
	else if (randItem->getType() == "WAND"){
		printShopGenerateWand();
	}
	else if (randItem->getType() == "HEALTH_POTION"){
		printShopGenerateHealthPotion();
	}
	else{
		printShopGenerateAttackPotion();
	}

	//The print statements above ask the user if they would like to buy the item generated (Y/N)
	//change user's choice char to whatever our input variable is called
	std::cin >> x; 

	if (x == "N"){
		//Display output of new level or monster OR loops back into screen with Fight, Items, and Run 
		//Break statement here? 
	}
	else if (x == "Y"){
		if (character->getCoins() >= randItem->getCost()){
			character->addItem(randItem);
			printItemBuyPass();
			character->setCoins(character->getCoins() - randItem->getCost());
		}
		else{
			printItemBuyFail();
			//User did not have enough coins to buy item, go to next level/monster 
		}
	}
}

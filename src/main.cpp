#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string& option) {
	return (option != "1" && option != "2" && option != "3");
}

std::string requestInput() {
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

int main() {
	Character* player = nullptr;
	Enemy* enemy = nullptr;
	enemy = new Monster();
	player = new Assassin();
	// player->inventory->getItem(0);

	Display::printIntro();

	switch (std::stoi(requestInput())) {
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
					Difficulty::setEasy(enemy);
					break;
				case 2:
					Difficulty::setNormal(enemy);
					break;
				case 3:
					Difficulty::setHard(enemy);
					break;
			}
			break;
		case 3:
			Display::printQuit();
			break;
	}

	

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

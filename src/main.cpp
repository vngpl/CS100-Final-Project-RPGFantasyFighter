#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string&);
const std::string requestInput(/*const std::string&*/);

int main() {
	Character* player = nullptr;

	Display::printNewline();
	Display::printNewline();
	Display::printNewline();
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
					// Difficulty::setEasy();
				// 2. Medium
					break;
				case 2:
					// Difficulty::setNormal();
					break;
				// 3. Hard
				case 3:
					// Difficulty::setHard();
					break;
			}
			break;
		// 3. Quit
		case 3:
			// Thank you for playing!
			Display::printQuit(player);
			break;
	}
	
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

	delete player;
	player = nullptr;

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
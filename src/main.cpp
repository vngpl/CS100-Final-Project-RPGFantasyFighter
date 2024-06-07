#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string& option) {
	return (option != "1" && option != "2" && option != "3");
}

// std::string makeChoice() {
//     std::string option;
//     std::cin >> option;
//     while (invalidOption(option)) {
//         Display::printInvalidInput();
//         std::cin >> option;
//     }
//     return option;
// }

int main() {
	Character* player = nullptr;
	player = new Character(ASSASSIN, 10, 50);
	std::string option;

	Display::printIntro();

	std::cin >> option;

	while (invalidOption(option)) {
		std::cin >> option;
		Display::printInvalidInput();
	}

	// std::string option = makeChoice();

	Display::printNewline();

	switch (std::stoi(option)) {
		case 1:
			Display::printCharacterCreation();
			break;
		case 2:
			Display::printSettings();
			break;
		case 3:
			Display::printQuit();
			break;
	}

	std::cin >> option;

	while (invalidOption(option)) {
		std::cin >> option;
		Display::printInvalidInput();
	}

	Display::printNewline();

	
	// Character Creation
	switch (std::stoi(option)) {
		case 1:
			// player = new Character(ASSASSIN);
			break;
		case 2:
			// player = new Warrior;
			break;
		case 3:
			// player = new Wizard;
			break;
	}

	Display::printType(player);
	Display::printHealth(player);
	Display::printLevel(player);
	Display::printExperience(player);
	Display::printAttackStrength(player);


	return 0;
}

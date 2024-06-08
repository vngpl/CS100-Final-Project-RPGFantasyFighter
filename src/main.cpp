#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string& option) {
	return (option != "1" && option != "2" && option != "3");
}

int main() {
	Character* player = nullptr;
	std::string option;

	Display::printIntro();

	std::cin >> option;

	while (invalidOption(option)) {
		std::cin >> option;
		Display::printInvalidInput();
	}

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
			player = new Assassin();
			break;
		case 2:
			player = new Warrior();
			break;
		case 3:
			player = new Wizard();
			break;
	}

	Display::printCharacterInformation(player);

	delete player;
	player = nullptr;

	return 0;
}

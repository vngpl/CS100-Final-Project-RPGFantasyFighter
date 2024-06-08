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
					// EASY
					break;
				case 2:
					// MEDIUM
					break;
				case 3:
					// HARD
					break;
			}
			break;
		case 3:
			Display::printQuit();
			break;
	}

	Display::printNewline();

	Display::printInventoryItems(player);

	delete player;
	player = nullptr;

	return 0;
}

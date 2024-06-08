#include <iostream>
#include "../header/init.hpp"

bool invalidOption(const std::string&);
const std::string& requestInput(const std::string&);

int main() {
	Character* player = nullptr;
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
			Display::printQuit(player);
			break;
	}

	Display::printNewline();

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
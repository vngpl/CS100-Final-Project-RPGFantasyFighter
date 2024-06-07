#include "../header/Display.hpp"

void Display::printIntro() {
	std::cout << "WELCOME TO FANTASY FIGHTER I" << std::endl;
	std::cout << std::endl;
	
	std::cout << "1. Character Creation" << std::endl
			  << "2. Settings" << std::endl
			  << "3. Quit" << std::endl;
	std::cout << std::endl;
	
	std::cout << "SELECT AN OPTION: ";
	// switch (std::stoi(option)) {
	// 	case 1:
	// 		printCharacterCreation();
	// 		break;
	// 	case 2:
	// 		printSettings();
	// 		break;
	// 	case 3:
	// 		printQuit();
	// 		break;
	// }
}

void Display::printInvalidInput() {
	std::cout << "Invalid input. Please enter an integer value based on the above options." << std::endl;
}

// void Display::printCharacterName(const string& name) const {
// 	std::string name;
// 	std::string typeOption;
// 	CharacterType type;

// 	std::cout << "ENTER CHARACTER INFORMATION:" << std::endl
// 			  << "Name: ";
// 	// std::cin >> name;
// 	std::cout << std::endl;
// }

void Display::printCharacterCreation() {
	std::cout << "CHOOSE YOUR FIGHTER'S CLASS: " << std::endl
			  << "1. Assassin" << std::endl
			  << "2. Warrior" << std::endl 
			  << "3. Wizard" << std::endl;
	std::cout << std::endl;
	
	// std::cout << "SELECT AN OPTION: ";
	// while (true) {
	// 	std::cin >> typeOption;
	// 	if (typeOption != "1" && typeOption != "2" && typeOption != "3") {
	// 		std::cout << "Invalid input. Please enter an integer value based on the above options." << std::endl;		
	// 	}
	// 	else {
	// 		break;
	// 	}
	// }
	// std::cout << std::endl;

	// std::cin >> type;
}

void Display::printSettings() {
	std::cout << "settings" << std::endl;	
}

void Display::printQuit() {
	std::cout << "Thank you for playing!" << std::endl
			  << "You finished with: " << std::endl
			  << "DISPLAY STATS" << std::endl;	
}
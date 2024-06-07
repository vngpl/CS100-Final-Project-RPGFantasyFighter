#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <string>

#include "Character.hpp"

class Display {
	private:

	public:
		static void printIntro();
		static void printCharacterCreation();
		static void printSettings();
		static void printQuit();
		static void printStats();

		static void printCharacterInformation(Character*);
		static void printType(Character*);
		static void printHealth(Character*);
		static void printLevel(Character*);
		static void printExperience(Character*);
		static void printAttackStrength(Character*);
		static void printDeath(Character*);

		static void printNewline();
		static void printInvalidInput();
};

void printIntro() {
	std::cout << "WELCOME TO FANTASY FIGHTER I" << std::endl << std::endl;

	std::cout << "1. Character Creation" << std::endl
			  << "2. Settings" << std::endl
			  << "3. Quit" << std::endl << std::endl;
	std::cout << "SELECT AN OPTION: ";
}

void printCharacterCreation() {
	std::cout << "CHOOSE YOUR FIGHTER TYPE: " << std::endl
			  << "1. Assassin (+20 ATK, -10 HP)" << std::endl
			  << "2. Warrior (+25 HP)" << std::endl
			  << "3. Wizard" << std::endl << std::endl;
	std::cout << "SELECT AN OPTION: ";
}

void printSettings() {
	std::cout << "CHOOSE GAME DIFFICULTY: " << std::endl
			  << "1. Easy" << std::endl
			  << "2. Medium" << std::endl
			  << "3. Hard" << std::endl << std::endl;
	std::cout << "SELECT AN OPTION: ";
}

void printQuit() {
	std::cout << "Thank you for playing!" << std::endl
			  << "You finished with: " << std::endl
			  << "*DISPLAY STATS HERE*" << std::endl << std::endl;
}

void printCharacterInformation(Character* character) {
	std::cout << "TYPE: " << character->getType() << std::endl;
	std::cout << "HEALTH: " << character->getHealth() << std::endl;
	std::cout << "LEVEL: " << character->getLevel() << std::endl;
	std::cout << "EXPERIENCE: " << character->getExperience() << std::endl;
	std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl;
}

void printType(Character* character) {
	std::cout << "TYPE: " << character->getType() << std::endl << std::endl;
}

void printHealth(Character* character) {
	std::cout << "HEALTH: " << character->getHealth() << std::endl << std::endl;
}

void printLevel(Character* character) {
	std::cout << "LEVEL: " << character->getLevel() << std::endl << std::endl;
}

void printExperience(Character* character) {
	std::cout << "EXPERIENCE: " << character->getExperience() << std::endl << std::endl;
}

void printAttackStrength(Character* character) {
	std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl << std::endl;
}

void printDeath(Character* character) {
	std::cout << "YOU HAVE DIED." << std::endl << std::endl;
}

void printNewline() {
	std::cout << std::endl;
}

void printInvalidInput() {
	std::cout << "Invalid input. Please enter an integer value based on the above options." << std::endl << std::endl;
}


#endif

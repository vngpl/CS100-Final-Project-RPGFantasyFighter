#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <string>

#include "Character.hpp"

class Display
{
	public:
		static void printIntro() {
			std::cout << "WELCOME TO FANTASY FIGHTER I" << std::endl
					<< std::endl;

			std::cout << "1. Character Creation" << std::endl
					<< "2. Settings" << std::endl
					<< "3. Quit" << std::endl
					<< std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printCharacterCreation() {
			std::cout << "CHOOSE YOUR FIGHTER TYPE: " << std::endl
					<< "1. Assassin (+20 ATK, -10 HP)" << std::endl
					<< "2. Warrior (+25 HP)" << std::endl
					<< "3. Wizard" << std::endl
					<< std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printSettings() {
			std::cout << "CHOOSE GAME DIFFICULTY: " << std::endl
					<< "1. Easy" << std::endl
					<< "2. Medium" << std::endl
					<< "3. Hard" << std::endl
					<< std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printQuit() {
			std::cout << "Thank you for playing!" << std::endl
					<< "You finished with: " << std::endl
					<< "*DISPLAY STATS HERE*" << std::endl
					<< std::endl;
		}

		static void printCharacterInformation(Character *character) {
			std::cout << "TYPE: " << character->getType() << std::endl;
			std::cout << "HEALTH: " << character->getHealth() << std::endl;
			std::cout << "LEVEL: " << character->getLevel() << std::endl;
			std::cout << "EXPERIENCE: " << character->getExperience() << std::endl;
			std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl;
		}

		static void printType(Character *character) {
			std::cout << "TYPE: " << character->getType() << std::endl
					<< std::endl;
		}

		static void printHealth(Character *character) {
			std::cout << "HEALTH: " << character->getHealth() << std::endl
					<< std::endl;
		}

		static void printLevel(Character *character) {
			std::cout << "LEVEL: " << character->getLevel() << std::endl
					<< std::endl;
		}

		static void printExperience(Character *character) {
			std::cout << "EXPERIENCE: " << character->getExperience() << std::endl
					<< std::endl;
		}

		static void printAttackStrength(Character *character) {
			std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl
					<< std::endl;
		}

		static void printDeath(Character *character) {
			std::cout << "YOU HAVE DIED." << std::endl
					<< std::endl;
		}

		static void printNewline() {
			std::cout << std::endl;
		}

		static void printInvalidInput() {
			std::cout << "Invalid input. Please enter an integer value based on the above options." << std::endl
					<< std::endl;
		}
};

#endif

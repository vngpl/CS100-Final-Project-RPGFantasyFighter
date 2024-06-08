#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <string>

#include "Character.hpp"

class Display {
	public:
		static void printIntro() {
			std::cout << "WELCOME TO FANTASY FIGHTER I" << std::endl << std::endl;

			std::cout << "1. Character Creation" << std::endl
					  << "2. Settings" << std::endl
					  << "3. Quit" << std::endl << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printCharacterCreation() {
			std::cout << "CHOOSE YOUR FIGHTER TYPE: " << std::endl << std::endl
					  << "1. Assassin (+20 ATK, -10 HP)" << std::endl
					  << "2. Warrior (+0 ATK, +25 HP)" << std::endl
					  << "3. Wizard (+0 ATK, +0 HP)" << std::endl << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printSettings() {
			std::cout << "CHOOSE GAME DIFFICULTY: " << std::endl << std::endl
					  << "1. Easy" << std::endl
					  << "2. Medium" << std::endl
					  << "3. Hard" << std::endl << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printQuit() {
			std::cout << "Thank you for playing!" << std::endl
					  << "You finished with: " << std::endl
					  << "*DISPLAY STATS HERE*" << std::endl << std::endl;
		}

		static void printCharacterInformation(Character *character) {
			std::cout << "TYPE: " << character->getType() << std::endl;
			std::cout << "HEALTH: " << character->getHealth() << std::endl;
			std::cout << "LEVEL: " << character->getLevel() << std::endl;
			std::cout << "EXPERIENCE: " << character->getExperience() << std::endl;
			std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl;
		}

		static void printType(Character *character) {
			std::cout << "TYPE: " << character->getType() << std::endl << std::endl;
		}

		static void printHealth(Character *character) {
			std::cout << "HEALTH: " << character->getHealth() << std::endl << std::endl;
		}

		static void printLevel(Character *character) {
			std::cout << "LEVEL: " << character->getLevel() << std::endl << std::endl;
		}

		static void printExperience(Character *character) {
			std::cout << "EXPERIENCE: " << character->getExperience() << std::endl << std::endl;
		}

		static void printAttackStrength(Character *character) {
			std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl << std::endl;
		}

		static void printDeath(Character *character) {
			std::cout << "YOU HAVE DIED." << std::endl << std::endl;
		}

		static void printNewline() {
			std::cout << std::endl;
		}

		static void printSelectOption() {
			std::cout << "SELECT AN OPTION: ";
		}

		static void printInvalidInput() {
			std::cout << "INVALID INPUT: Please enter an integer value based on the above options." << std::endl << std::endl;
		}

		static void printBattleOptions() {
			std::cout << "CHOOSE FIGHT OPTION:" << std::endl
					  << "1. Fight" << std::endl
					  << "2. Use Items" << std::endl
					  << "3. Run" << std::endl
					  << std::endl;
			std::cout << "SELECT AN OPTION: ";
  		}

		static void printInventoryItems(Character* character) {
			const std::vector<Item*>& items = character->getInventoryItems();
			if (character->inventoryIsEmpty()) {
				std::cout << "Inventory is empty." << std::endl;
			}
			else {
				for (auto item : items) {
					if (item->getType() == "SWORD") {
						std::cout << "You have a sword." << std::endl;
					}
					else if (item->getType() == "DAGGER") {
						std::cout << "You have a dagger." << std::endl;
					}
					else if (item->getType() == "WAND") {
						std::cout << "You have a wand." << std::endl;
					}
					else if (item->getType() == "HEALTH_POTION") {
						std::cout << "You have a health potion." << std::endl;
					}
					else {
						std::cout << "You have an attack potion." << std::endl;
					}
				}
			}
			// 	// bool hasWeapon = character->hasWeapon();
			// 	// bool hasPotion = character->hasPotion();
			// 	// if (hasWeapon && hasPotion) {
        	// 	// 	std::cout << "You have a weapon and a potion." << std::endl;
			// 	// }
			// 	// else if (hasPotion) {
			// 	// 	std::cout << "You have a potion." << std::endl;
			// 	// }
			// 	// else if (hasWeapon && hasPotion) {
			// 	// 	std::cout << "You have a weapon and a potion." << std::endl;
			// 	// }
			// }
		}

		static void printItemOptions(Character* character){
			if (character->IsEmpty()) {
				std::cout << "No item can be used." << std::endl;
			}
			else if (character->hasWeapon()) {
        		std::cout << "Equip the weapon? Y/N" << std::endl;
    		}	
			else if (character->hasPotion()) {
				std::cout << "Apply the potion? Y/N" << std::endl;
			}
			else {
				std::cout << "Use weapon or potion? N/W/P" << std::endl;
			}
		}	



		static void printUseSword(){
			std::cout << "Sword equiped! Attack boosted." << std::endl;
		}

		static void printUseDagger(){
			std::cout << "Dagger equiped! Attack boosted." << std::endl;
		}

		static void printUseWand(){
			std::cout << "Dagger equiped! Attack boosted." << std::endl;
		}

		static void printUseAttackPotion(){
			std::cout << "Attack potion applied. Attack boosted." << std::endl;
		}

		static void printUseHealthPotion(){
			std::cout << "Health potion applied. Health recovered." << std::endl;
		}



		static void printShopGenerateSword(){
			std::cout << "The shop spawned a Sword, with cost 1. Will you buy? Y/N" << std::endl;
		}

		static void printShopGenerateDagger(){
			std::cout << "The shop spawned a Dagger, with cost 2. Will you buy? Y/N" << std::endl;
		}

		static void printShopGenerateWand(){
			std::cout << "The shop spawned a Wand, with cost 3. Will you buy? Y/N" << std::endl;
		}

		static void printShopGenerateAttackPotion(){
			std::cout << "The shop spawned an Attack Potion, with cost 2. Will you buy? Y/N" << std::endl;
		}

		static void printShopGenerateHealthPotion(){
			std::cout << "The shop spawned a Health Potion, with cost 1. Will you buy? Y/N" << std::endl;
		}



		static void printItemBuyFail(){
			std::cout << "Not enough coins to buy." << std::endl;
		}

		static void printItemBuyPass(){
			std::cout << "Item bought and added to inventory." << std::endl;
		}
};

#endif

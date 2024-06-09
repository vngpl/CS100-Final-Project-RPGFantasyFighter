#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Enemy.hpp"

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
			std::cout << "Base stats: 100 ATK, 100 HP" << std::endl << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printSettings() {
			std::cout << "CHOOSE GAME DIFFICULTY: " << std::endl << std::endl
					  << "1. EASY" << std::endl
					  << "2. MEDIUM" << std::endl
					  << "3. HARD" << std::endl << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void printQuit(Character* character) {
			std::cout << "Thank you for playing!" << std::endl << std::endl;
			if (character != nullptr) {
				std::cout << "As a(n) " << character->getType() << " you finished with:" << std::endl;
				printCharacterInformation(character);
			}
		}

		static void printCharacterInformation(Character* character) {
			std::cout << "HEALTH: " << character->getHealth() << std::endl
			 		  << "LEVEL: " << character->getLevel() << std::endl
			 		  << "EXPERIENCE: " << character->getExperience() << std::endl
			 		  << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl
					  << "MONSTERS SLAIN: " << character->getMonstersSlain() << std::endl << std::endl;
		}


		//DISPLAY MONSTER STATS
		static void printMONSTERInformation(Enemy *enemy) {
			std::cout << "MONSTER TYPE: " << enemy->getType() << std::endl;
			std::cout << "MONSTER HEALTH: " << enemy->getHealth() << std::endl;
			std::cout << "MONSTER LEVEL: " <<  enemy->getLevel() << std::endl;
			std::cout << "MONSTER ATTACK STRENGTH: " << enemy->getAttackStrength() << std::endl;
		}

			std::cout << "TYPE: " << character->getType() << std::endl << std::endl;
		}

		static void printHealth(Character* character) {
			std::cout << "HEALTH: " << character->getHealth() << std::endl << std::endl;
		}

		static void printLevel(Character* character) {
			std::cout << "LEVEL: " << character->getLevel() << std::endl << std::endl;
		}

		static void printExperience(Character* character) {
			std::cout << "EXPERIENCE: " << character->getExperience() << std::endl << std::endl;
		}

		static void printAttackStrength(Character* character) {
			std::cout << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl << std::endl;
		}



		//DISPLAY EACH MONSTER STAT 
		static void printAttackStrengthMONSTER(Enemy *enemy) {
			std::cout << "MONSTER ATTACK STRENGTH: " << enemy->getAttackStrength() << std::endl << std::endl;
		}

		static void printHealthMONSTER(Enemy *enemy) {
			std::cout << "MONSTER HEALTH: " << enemy->getHealth() << std::endl << std::endl;
		}

		static void printLevelMONSTER(Enemy *enemy) {
			std::cout << "MONSTER LEVEL: " << enemy->getLevel() << std::endl << std::endl;
		}



		static void printDeath(Character* character) {
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
			std::cout << "CHOOSE FIGHT OPTION:" << std::endl << std::endl
					  << "1. CHALLENGE AN OPPONENT" << std::endl
					  << "2. USE ITEM" << std::endl
					  << "3. RUN" << std::endl
					  << std::endl;
			std::cout << "SELECT AN OPTION: ";
  		}

		static void printInventoryItems(Character* character) {
			const std::vector<Item*>& items = character->getInventoryItems();
			if (character->inventoryIsEmpty()) {
				std::cout << "INVENTORY IS EMPTY" << std::endl;
			}
			else {
				for (auto item : items) {
					if (item->getType() == "SWORD") {
						std::cout << "YOU HAVE A SWORD." << std::endl;
					}
					else if (item->getType() == "DAGGER") {
						std::cout << "YOU HAVE A DAGGER." << std::endl;
					}
					else if (item->getType() == "WAND") {
						std::cout << "YOU HAVE A WAND." << std::endl;
					}
					else if (item->getType() == "HEALTH_POTION") {
						std::cout << "YOU HAVE A HEALTH POTION." << std::endl;
					}
					else {
						std::cout << "YOU HAVE AN ATTACK POTION." << std::endl;
					}
				}
			}
		}

		static void printItemOptions(Character* character){
			if (character->inventoryIsEmpty()) {
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

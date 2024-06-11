#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include "Character.hpp"
#include "Enemy.hpp"

class Display {
	public:
		static void inline printIntro() {
			std::cout << "WELCOME TO FANTASY FIGHTER I" << std::endl
					  << std::endl
					  << "CHOOSE GAME DIFFICULTY: " << std::endl
					  << std::endl
					  << "1. EASY" << std::endl
					  << "2. MEDIUM" << std::endl
					  << "3. HARD" << std::endl
					  << std::endl
					  << "SELECT AN OPTION: ";
		}

		static void inline printCharacterCreation() {
			std::cout << std::endl
					  << "CHOOSE YOUR FIGHTER TYPE:" << std::endl
					  << std::endl
					  << "1. Assassin (+20 ATK, -10 HP)" << std::endl
					  << "2. Warrior (+0 ATK, +25 HP)" << std::endl
					  << "3. Wizard (+0 ATK, +0 HP)" << std::endl
					  << std::endl;
			std::cout << "Base stats: 100 ATK, 100 HP" << std::endl
					  << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void inline printQuit(Character* character) {
			std::cout << std::endl
					  << "Thank you for playing!" << std::endl
					  << std::endl;
			if (character != nullptr) {
				std::cout << "As a(n) " << character->getType() << " you finished with:" << std::endl;
				printCharacterInformation(character);
			}
		}

		static void inline printCharacterInformation(Character* character) {
			std::cout << std::endl
					  << "YOU ARE A(N) " << character->getType() << " WITH:" << std::endl
					  << std::endl
					  << "HEALTH: " << character->getHealth() << std::endl
			 		  << "LEVEL: " << character->getLevel() << std::endl
			 		  << "EXPERIENCE: " << character->getExperience() << std::endl
			 		  << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl
					  << "MONSTERS SLAIN: " << character->getMonstersSlain() << std::endl
					  << std::endl;
		}

		//DISPLAY MONSTER STATS
		static void inline printMONSTERInformation(Enemy *enemy) {
			std::cout << std::endl
					  << "MONSTER TYPE: " << enemy->getType() << std::endl
					  << "MONSTER HEALTH: " << enemy->getHealth() << std::endl
					  << "MONSTER LEVEL: " <<  enemy->getLevel() << std::endl
					  << "MONSTER ATTACK STRENGTH: " << enemy->getAttackStrength() << std::endl;
		}

		static void inline printStatAllocation(Character *character) {
			std::cout << std::endl
					  << "CHOOSE STAT ALLOCATION:" << std::endl
					  << std::endl
					  << "1. Upgrade Health" << std::endl
					  << "2. Upgrade Strength" << std::endl
					  << std::endl
					  << "SELECT AN OPTION: ";
		}

		static void inline printNEWAttackStrength(Character *character) {
			std::cout << std::endl
					  << "ATTACK STRENGTH (ADDED +5): " << character->getAttackStrength() << std::endl
					  << std::endl;
		}

		static void inline printNEWHealth(Character *character) {
			std::cout << std::endl
					  << "HEALTH (ADDED +10): " << character->getHealth() << std::endl
					  << std::endl;
		}

		static void inline printLevelcount(Character *character) {
			std::cout << std::endl
					  << "EXP(current): " << character->getExperience() << "/" << character->getNextExperience()
			<< std::endl;
		}

		static void inline printType(Character *character) {
			std::cout << std::endl
					  << "TYPE: " << character->getType() << std::endl
					  << std::endl;
		}

		static void inline printHealth(Character* character) {
			std::cout << std::endl
					  << "HEALTH: " << character->getHealth() << std::endl
					  << std::endl;
		}

		static void inline printLevel(Character* character) {
			std::cout << std::endl
					  << "LEVEL: " << character->getLevel() << std::endl
					  << std::endl;
		}

		static void inline printExperience(Character* character) {
			std::cout << std::endl
					  << "EXPERIENCE: " << character->getExperience() << std::endl
					  << std::endl;
		}

		static void inline printAttackStrength(Character* character) {
			std::cout << std::endl
					  << "ATTACK STRENGTH: " << character->getAttackStrength() << std::endl
					  << std::endl;
		}

		static void inline printCoins(Character *character) {
			std::cout << std::endl
					  << "COINS: " << character->getCoins() << std::endl
					  << std::endl;
		}

		//DISPLAY EACH MONSTER STAT
		static void inline printAttackStrengthMONSTER(Enemy *enemy) {
			std::cout << std::endl
					  << "MONSTER ATTACK STRENGTH: " << enemy->getAttackStrength() << std::endl
					  << std::endl;
		}

		static void inline printHealthMONSTER(Enemy *enemy) {
			std::cout << std::endl
					  << "MONSTER HEALTH: " << enemy->getHealth() << std::endl
					  << std::endl;
		}

		static void inline printLevelMONSTER(Enemy *enemy) {
			std::cout << std::endl
					  << "MONSTER LEVEL: " << enemy->getLevel() << std::endl
					  << std::endl;
		}

		static void inline printDeath(Character* character) {
			std::cout << std::endl
					  << "YOU HAVE DIED." << std::endl
					  << std::endl;
		}

		static void inline printInvalidInput() {
			std::cout << std::endl
					  << "INVALID INPUT: Please enter an integer value based on the above options." << std::endl
					  << std::endl;
			std::cout << "SELECT AN OPTION: ";
		}

		static void inline printBattleOptions() {
			std::cout << std::endl
					  << "CHOOSE FIGHT OPTION:" << std::endl
					  << std::endl
					  << "1. CHALLENGE AN OPPONENT" << std::endl
					  << "2. SHOW INVENTORY" << std::endl
					  << "3. RUN" << std::endl
					  << std::endl;
			std::cout << "SELECT AN OPTION: ";
  		}

		static void inline printInventoryIsEmpty(Character* character) {
			std::cout << std::endl
					  << "INVENTORY IS EMPTY." << std::endl
					  << std::endl;
		}

		static void inline printInventoryItems(Character* character) {
			const std::vector<Item*>& items = character->getInventoryItems();
			std::cout << "INVENTORY: " << std::endl
						<< std::endl;
			for (auto item : items) {
				if (item->getType() == "SWORD") {
					std::cout << "SWORD" << std::endl;
				}
				else if (item->getType() == "DAGGER") {
					std::cout << "DAGGER" << std::endl;
				}
				else if (item->getType() == "WAND") {
					std::cout << "WAND" << std::endl;
				}
				else if (item->getType() == "HEALTH_POTION") {
					std::cout << "HEALTH POTION" << std::endl;
				}
				else {
					std::cout << "ATTACK POTION" << std::endl;
				}
			}
			std::cout << std::endl;
		}

		static void inline printItemOptions(Character* character){
			if (character->hasWeapon()) {
				std::cout << std::endl
						  << "Equip the weapon? Y/N" << std::endl
						  << std::endl;
    		}
			else if (character->hasPotion()) {
				std::cout << std::endl
						  << "Apply the potion? Y/N" << std::endl
						  << std::endl;
			}
			else {
				std::cout << std::endl
						  << "Use weapon or potion? N/W/P" << std::endl
						  << std::endl;
			}
		}

		static void inline printUseSword(){
			std::cout << std::endl
					  << "Sword equiped! Attack boosted." << std::endl
					  << std::endl;
		}

		static void inline printUseDagger(){
			std::cout << std::endl
					  << "Dagger equiped! Attack boosted." << std::endl
					  << std::endl;
		}

		static void inline printUseWand(){
			std::cout << std::endl
					  << "Dagger equiped! Attack boosted." << std::endl
					  << std::endl;
		}

		static void inline printUseAttackPotion(){
			std::cout << std::endl
					  << "Attack potion applied. Attack boosted." << std::endl
					  << std::endl;
		}

		static void inline printUseHealthPotion(){
			std::cout << std::endl
					  << "Health potion applied. Health recovered." << std::endl
					  << std::endl;
		}

		static void inline printShopGenerateSword(){
			std::cout << std::endl
					  << "The shop spawned a Sword, with cost 1. Will you buy? Y/N" << std::endl
					  << std::endl;
		}

		static void inline printShopGenerateDagger(){
			std::cout << std::endl
					  << "The shop spawned a Dagger, with cost 2. Will you buy? Y/N" << std::endl
					  << std::endl;
		}

		static void inline printShopGenerateWand(){
			std::cout << std::endl
					  << "The shop spawned a Wand, with cost 3. Will you buy? Y/N" << std::endl
					  << std::endl;
		}

		static void inline printShopGenerateAttackPotion(){
			std::cout << std::endl
					  << "The shop spawned an Attack Potion, with cost 2. Will you buy? Y/N" << std::endl
					  << std::endl;
		}

		static void inline printShopGenerateHealthPotion(){
			std::cout << std::endl
					  << "The shop spawned a Health Potion, with cost 1. Will you buy? Y/N" << std::endl
					  << std::endl;
		}

		static void inline printItemBuyFail(){
			std::cout << std::endl
					  << "Not enough coins to buy." << std::endl
					  << std::endl;
		}

		static void inline printItemBuyPass(){
			std::cout << std::endl
					  << "Item bought and added to inventory." << std::endl
					  << std::endl;
		}
};

#endif

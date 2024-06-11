#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <sstream>
#include <vector>

#include "Character.hpp"
#include "Enemy.hpp"

class Display {
 private:
  static void printBox(const std::string& message) {
    std::string border = "+" + std::string(message.length() + 2, '-') + "+";
    std::cout << border << std::endl;
    std::cout << "| " << message << " |" << std::endl;
    std::cout << border << std::endl;
  }

  static void printMultiLineBox(const std::vector<std::string>& lines) {
    size_t maxLength = 0;
    for (const std::string& line : lines) {
      if (line.length() > maxLength) {
        maxLength = line.length();
      }
    }

    std::string border = "+" + std::string(maxLength + 2, '-') + "+";
    std::cout << border << std::endl;
    for (const std::string& line : lines) {
      std::cout << "| " << line << std::string(maxLength - line.length(), ' ')
                << " |" << std::endl;
    }
    std::cout << border << std::endl;
  }

 public:
  static void inline printIntro() {
    std::vector<std::string> lines = {"WELCOME TO FANTASY FIGHTER I",
                                      "",
                                      "CHOOSE GAME DIFFICULTY: ",
                                      "1. EASY",
                                      "2. MEDIUM",
                                      "3. HARD",
                                      "",
                                      "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printCharacterCreation() {
    std::vector<std::string> lines = {"CHOOSE YOUR FIGHTER TYPE:",
                                      "",
                                      "1. Assassin (+20 ATK, -10 HP)",
                                      "2. Warrior (+0 ATK, +25 HP)",
                                      "3. Wizard (+0 ATK, +0 HP)",
                                      "",
                                      "Base stats: 100 ATK, 100 HP",
                                      "",
                                      "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printQuit(Character* character) {
    printBox("Thank you for playing!");
    if (character != nullptr) {
      std::vector<std::string> lines = {"As a(n) " + character->getType() +
                                        " you finished with:"};
      std::ostringstream ss;
      ss << "HEALTH: " << character->getHealth();
      lines.push_back(ss.str());
      ss.str("");
      ss << "LEVEL: " << character->getLevel();
      lines.push_back(ss.str());
      ss.str("");
      ss << "EXPERIENCE: " << character->getExperience();
      lines.push_back(ss.str());
      ss.str("");
      ss << "ATTACK STRENGTH: " << character->getAttackStrength();
      lines.push_back(ss.str());
      ss.str("");
      ss << "MONSTERS SLAIN: " << character->getMonstersSlain();
      lines.push_back(ss.str());
      printMultiLineBox(lines);
    }
  }

  static void inline printCharacterInformation(Character* character) {
    std::vector<std::string> lines = {"YOU ARE A(N) " + character->getType() +
                                      " WITH:"};
    std::ostringstream ss;
    ss << "HEALTH: " << character->getHealth();
    lines.push_back(ss.str());
    ss.str("");
    ss << "LEVEL: " << character->getLevel();
    lines.push_back(ss.str());
    ss.str("");
    ss << "EXPERIENCE: " << character->getExperience();
    lines.push_back(ss.str());
    ss.str("");
    ss << "ATTACK STRENGTH: " << character->getAttackStrength();
    lines.push_back(ss.str());
    ss.str("");
    ss << "MONSTERS SLAIN: " << character->getMonstersSlain();
    lines.push_back(ss.str());
    printMultiLineBox(lines);
  }

  static void inline printMONSTERInformation(Enemy* enemy) {
    std::vector<std::string> lines = {
        "MONSTER TYPE: " + enemy->getType(),
        "MONSTER HEALTH: " + std::to_string(enemy->getHealth()),
        "MONSTER LEVEL: " + std::to_string(enemy->getLevel()),
        "MONSTER ATTACK STRENGTH: " +
            std::to_string(enemy->getAttackStrength())};
    printMultiLineBox(lines);
  }

  static void inline printStatAllocation() {
    std::vector<std::string> lines = {
        "CHOOSE STAT ALLOCATION:", "", "1. Upgrade Health",
        "2. Upgrade Strength",     "", "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printNEWAttackStrength(Character* character) {
    std::ostringstream ss;
    ss << "ATTACK STRENGTH (ADDED +5): " << character->getAttackStrength();
    printBox(ss.str());
  }

  static void inline printNEWHealth(Character* character) {
    std::ostringstream ss;
    ss << "HEALTH (ADDED +10): " << character->getHealth();
    printBox(ss.str());
  }

  static void inline printLevelcount(Character* character) {
    std::ostringstream ss;
    ss << "EXP(current): " << character->getExperience() << "/"
       << character->getNextExperience();
    printBox(ss.str());
  }

  static void inline printType(Character* character) {
    printBox("TYPE: " + character->getType());
  }

  static void inline printHealth(Character* character) {
    std::ostringstream ss;
    ss << "HEALTH: " << character->getHealth();
    printBox(ss.str());
  }

  static void inline printLevel(Character* character) {
    std::ostringstream ss;
    ss << "LEVEL: " << character->getLevel();
    printBox(ss.str());
  }

  static void inline printExperience(Character* character) {
    std::ostringstream ss;
    ss << "EXPERIENCE: " << character->getExperience();
    printBox(ss.str());
  }

  static void inline printAttackStrength(Character* character) {
    std::ostringstream ss;
    ss << "ATTACK STRENGTH: " << character->getAttackStrength();
    printBox(ss.str());
  }

  static void inline printCoins(Character* character) {
    std::ostringstream ss;
    ss << "COINS: " << character->getCoins();
    printBox(ss.str());
  }

  static void inline printAttackStrengthMONSTER(Enemy* enemy) {
    std::ostringstream ss;
    ss << "MONSTER ATTACK STRENGTH: " << enemy->getAttackStrength();
    printBox(ss.str());
  }

  static void inline printHealthMONSTER(Enemy* enemy) {
    std::ostringstream ss;
    ss << "MONSTER HEALTH: " << enemy->getHealth();
    printBox(ss.str());
  }

  static void inline printLevelMONSTER(Enemy* enemy) {
    std::ostringstream ss;
    ss << "MONSTER LEVEL: " << enemy->getLevel();
    printBox(ss.str());
  }

  static void inline printDeath() {
    printBox("YOU HAVE DIED.");
  }

  static void inline printInvalidInput() {
    std::vector<std::string> lines = {
        "INVALID INPUT: Please enter an integer value based on the above "
        "options.",
        "", "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printBattleOptions() {
    std::vector<std::string> lines = {
        "CHOOSE FIGHT OPTION:", "",       "1. CHALLENGE AN OPPONENT",
        "2. SHOW INVENTORY",    "3. RUN", "",
        "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printInventoryIsEmpty() {
    printBox("INVENTORY IS EMPTY.");
  }

  static void inline printInventoryItems(Character* character) {
    const std::vector<Item*>& items = character->getInventoryItems();
    std::vector<std::string> lines = {"INVENTORY:"};
    for (auto item : items) {
      if (item == nullptr) {
        continue;
      }
      lines.push_back(item->getType());
    }
    printMultiLineBox(lines);
  }

  static void inline printItemOptions(Character* character) {
    if (character->hasWeapon() && character->hasPotion()) {
      printBox("Equip [W]eapon/[P]otion/[N]either");
    } else if (character->hasWeapon()) {
      printBox("Equip the weapon? Y/N");
    } else if (character->hasPotion()) {
      printBox("Apply the potion? Y/N");
    }
  }

  static void inline printUseSword() {
    printBox("Sword equipped! Attack boosted.");
  }

  static void inline printUseDagger() {
    printBox("Dagger equipped! Attack boosted.");
  }

  static void inline printUseWand() {
    printBox("Wand equipped! Attack boosted.");
  }

  static void inline printUseAttackPotion() {
    printBox("Attack potion applied. Attack boosted.");
  }

  static void inline printUseHealthPotion() {
    printBox("Health potion applied. Health restored.");
  }

  static void inline printShopGenerateSword() {
    printBox("The shop spawned a Sword, with cost 1. Will you buy? Y/N");
  }

  static void inline printShopGenerateDagger() {
    printBox("The shop spawned a Dagger, with cost 2. Will you buy? Y/N");
  }

  static void inline printShopGenerateWand() {
    printBox("The shop spawned a Wand, with cost 3. Will you buy? Y/N");
  }

  static void inline printShopGenerateAttackPotion() {
    printBox(
        "The shop spawned an Attack Potion, with cost 2. Will you buy? Y/N");
  }

  static void inline printShopGenerateHealthPotion() {
    printBox(
        "The shop spawned a Health Potion, with cost 1. Will you buy? Y/N");
  }

  static void inline printShopOption() {
    std::vector<std::string> lines = {
        "Welcome to the Shop! What do you want to buy?",
        "",
        "1. Sword (+10 attack) - 1 coin",
        "2. Dagger (+5 attack) - 2 coins",
        "3. Wand (+20 attack) - 3 coins",
        "4. Attack Potion (+15 attack) - 2 coins",
        "5. Health Potion (+20 health) - 1 coin",
        "",
        "SELECT AN OPTION: "};
    printMultiLineBox(lines);
  }

  static void inline printNotEnoughCoins() {
    printBox("Not enough coins.");
  }

  static void inline printInventoryFull() {
    printBox("Inventory is full.");
  }

  // static void inline printNewline() {
  //   std::cout << "================================" << std::endl;
  // }

  static void inline printItemBuyFail() {
    std::cout << std::endl
              << "Not enough coins to buy." << std::endl
              << std::endl;
  }

  static void inline printItemBuyPass() {
    std::cout << std::endl
              << "Item bought and added to inventory." << std::endl
              << std::endl;
  }

  static void inline printEnemy(int32_t id) {
    printBox("Fight against #" + std::to_string(id) + " enemy");
  }

  static void inline printWinning() {
    printBox("Congraduations! You Win!");
  }

  static void inline printGameOver() {
    printBox("=== GAME OVER ===");
  }
};

#endif

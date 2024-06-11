#include <cmath>
#include <iostream>
#include <string>

using namespace std;
#include "../header/Character.hpp"
#include "../header/EXP.hpp"
#include "../header/Enemy.hpp"

Experience::Experience(int level, double exp, Character* character, Enemy* enemy)
    : level(level), exp(exp) {
  // level = level;
  expNext = (50.0 / 24) * (pow(level, 3) - 6 * pow(level, 2) + (level * 17) - 12);
  // exp = exp;
  levelMonster = enemy->getLevel();
  healthXP = character->getMaxHealth();
  strengthXP = character->getAttackStrength();
  healthMonster = enemy->getHealth();
  character = character;
}

double Experience::getEXP() {
  return exp;
}

// double Experience::getNextEXP() { return expNext; }

int Experience::getLevel() {
  return level;
}

int Experience::getLevelMonster() {
  return levelMonster;
}

// void setHealthMonster(double health) { healthMonster = enemy->getHealth(); }

int Experience::getMonsterHealth() {
  return healthMonster;
}

int Experience::getHP() {
  return healthXP;
}

double Experience::getNextEXP() {
  return expNext = (50.0 / 24) *
                         (pow(level, 3) - 6 * pow(level, 2) + (level * 17) - 12);
}

bool Experience::updateLevel() {
  bool leveledUp = false;  // Flag to track if any level-up occurred

  while (exp >= expNext) {
    level++;         // Level up
    exp -= expNext;  // Subtract experience
    expNext =
        (50.0 / 24) * (pow(level, 3) - 6 * pow(level, 2) + (level * 17) - 12);
    // Calculate experience required for the next level
    skillPoints++;  // Gain a skill point to allocate to strength or health
    leveledUp = true;     // Set flag to true indicating a level-up occurred
  }

  return leveledUp;  // Return true if any level-up occurred
}

// double Experience::gainExperience(double healthMonster, int levelMonster) {
//     if (healthMonster <= 0) {
//         return ((4.0 * pow(levelMonster, 3.0)) / 5.0); // Gain xp of Monster
//     }
//     else {
//         return 0; // Haven't killed Monster
//     }
// }

double Experience::gainExperience() {
  if (healthMonster <= 0) {
    exp += ((4.0 * pow(levelMonster, 3.0)) / 5.0);  // Make the level gained by the monster
    // experience += ((4.0 * pow(levelMONSTER, 3)) / 5);
    return exp;  // Gain xp of Monster
  } else {
    return exp;  // Havent killed Monster
  }
}

void Experience::pointAssign(int input) {
  int healthADD = 10;
  int strengthADD = 5;

  bool spendingSkillPoints = true;

  while (spendingSkillPoints && skillPoints > 0) {
    if (input == 1) {
      healthXP += healthADD;
      if (character) {
        character->setHealth(healthXP);  // Update health using the Character object
      }
      // void Character::setHealth(int newHealth) { health = newHealth; }
      skillPoints--;  // Decrease skillPoints by 1
    } else if (input == 2) {
      strengthXP += strengthADD;
      if (character) {
        character->setAttackStrength(strengthXP);  // Update health using the Character object
      }
      skillPoints--;  // Decrease skillPoints by 1
    } else if (input == 0) {
      spendingSkillPoints = false;  // Exit loop if input is 0
    }
  }
}

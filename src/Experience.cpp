#include<iostream>
#include<string>
#include<cmath>

using namespace std;
#include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Experience.hpp"

Experience::Experience(int level, double expNext, double exp, Character* character, Enemy* enemy) {
    this->level = level;
    this->expNext = expNext;
    this->exp = exp;
    this->levelMonster = enemy->getLevel();
    this->healthXP = character->getMAXHealth();
    this->strengthXP = character->getAttackStrength();
    this->healthMonster = enemy->getHealth();
    this->character = character; 
}

double Experience::getEXP() { return exp; }

double Experience::getNextEXP() { return this->expNext; }

int Experience::getLevel() { return this->level; }

int Experience::getLevelMonster() { return this->levelMonster; }

int Experience::getMonsterHealth() { return this->healthMonster; }

int Experience::getHP() { return this->healthXP; }

// void Experience::setNextEXP() { this->expNext = (50.0/24) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12); }

bool Experience::updateLevel() {
    bool leveledUp = false; // Flag to track if any level-up occurred
    
    while (exp >= this->expNext) {
        this->level++; // Level up
        exp -= this->expNext; // Subtract experience
        this->expNext = (50.0/24) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12); 
        // Calculate experience required for the next level
        this->skillPoints++; // Gain a skill point to allocate to strength or health
        leveledUp = true; // Set flag to true indicating a level-up occurred
    }
    
    return leveledUp; // Return true if any level-up occurred
}

double Experience::gainExperience() {
    if (this->healthMonster <= 0) {
        exp += ((4.0 * pow(this->levelMonster, 3.0)) / 5.0); //Make the level gained by the monster 
        //experience += ((4.0 * pow(this->levelMONSTER, 3)) / 5); 
        return exp; //Gain xp of Monster
    }
    else {
        return exp; //Havent killed Monster
    }
}

void Experience::pointAssign(int input) {
    int healthADD = 10;
    int strengthADD = 5;

    bool spendingSkillPoints = true;

    while (spendingSkillPoints && this->skillPoints > 0) {
        if (input == 1) {
            healthXP += healthADD;
            if (character) {
                character->setHealth(healthXP); // Update health using the Character object
            }
            //void Character::setHealth(int newHealth) { health = newHealth; } 
            this->skillPoints--; // Decrease skillPoints by 1
        }
        else if (input == 2) {
            strengthXP = strengthADD;
            this->skillPoints--; // Decrease skillPoints by 1
        }
        else if (input == 0) {
            spendingSkillPoints = false; // Exit loop if input is 0
        }
    }
}




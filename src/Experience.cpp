#include<iostream>
#include<string>

using namespace std;
#include "../header/Character.hpp"
#include "../header/Monster.hpp"
#include "../header/Experience.hpp"
#include "../header/Health.hpp"
#include "../header/Strength.hpp"


Experience::Experience(int level, double exp, double expNext) 
    :level(level), exp(exp), expNext(expNext) {
}

double Experience::getEXP() { return this->exp; }

double Experience::getNextEXP() { return this->expNext; }

int Experience::getLevel() { return this->level; }

int Experience::getHP() { return this->hpMAX; }

void Experience::setNextEXP() { this->expNext = (50.0/24) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12); }

bool Experience::updateLevel() {
    while (this->exp >= this->expNext) {
        this->level++; //Level up
        this->exp -= this->expNext; //Gets rid of exp  
        this->expNext = (50.0/24) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12); 
        // Show how much more xp you need for the Next level
        this->skillPoints++; // Gain a Skill point to allocate either to strenght or health
        return true;
    }
    return false;
}

double Experience::gainExperience() {
    if (this->hpMonster <= 0) {
        this->exp += ((4.0 * pow(this->level, 3)) / 5);
        return this->exp; //Gain xp of Monster
    }
    else {
        return 0; //Havent killed Monster
    }
}

void Experience::pointAssign(int input) {
    Health hpADD; 
    Strength attackADD;
    bool spendingSkillPoints = true;

    while (spendingSkillPoints && this->skillPoints > 0) {
        if (input == 1) {
            this->hpMAX = hpADD.updateCharHealth(this->hpMAX);
            this->skillPoints--; // Decrease skillPoints by 1
        }
        else if (input == 2) {
            this->attackStrengthMAX = attackADD.updateCharStrength(this->attackStrengthMAX);
            this->skillPoints--; // Decrease skillPoints by 1
        }
        else if (input == 0) {
            spendingSkillPoints = false; // Exit loop if input is 0
        }
    }
}




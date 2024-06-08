#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __EXP_H__
#define __EXP_H__

#include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Experience.hpp"

class Experience { 
    private:
        int level = 5;
        double exp; //GIVEN FROM CHARACTER FILE
        int healthXP;
        int strengthXP;
        double expNext;
        int levelMonster; 
        int healthMonster;
        int skillPoints = 0;
        Character* character;
        // Enemy* enemy;

    public:
        bool updateLevel();
        double gainExperience();
        void pointAssign(int);

        Experience() {} // Default constructor
        Experience(int, double, double, Character*, Enemy*);
        // void setNextEXP();
        double getEXP();
        double getNextEXP();
        int getLevel();
        int getLevelMonster();
        int getHP();
        int getMonsterHealth();
        void setHPMAX(int);
};

#endif
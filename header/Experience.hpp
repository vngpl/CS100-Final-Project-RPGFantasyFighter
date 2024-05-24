#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __EXP_H__
#define __EXP_H__

#include "../header/Character.hpp"

class Experience { //public Character 
    private:
        int level = 5; //GIVEN FROM CHARACTER FILE
        double exp; //GIVEN FROM CHARACTER FILE
        double expNext = (50.0/24) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12);
        int skillPoints = 0;

    public:
        bool updateLevel();
        double gainExperience();
        void pointAssign(int);

        Experience() {} // Default constructor
        Experience(int, double, double);
        void setNextEXP();
        double getEXP();
        double getNextEXP();
        int getLevel();
        int getHP();

        int hp;
        int hpMAX = 100;
        int attackStrength;
        int attackStrengthMAX; //GIVEN FROM CHARACTER FILE
        // int speed;
        // int speedMAX;
    //MONSTER
        int hpMonster = 0;
        int hpMonsterEXP;
        // int hpMonsterMAX;

};

#endif
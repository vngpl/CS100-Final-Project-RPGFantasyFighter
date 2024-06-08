#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __DIFFICULT_H__
#define __DIFFICULT_H__
#include <utility> // for std::pair

#include "../header/Enemy.hpp"

class Difficulty {
private:
    Enemy* enemy;

public:
    static void setEasy(Enemy*);
    static void setNormal(Enemy*);
    static void setHard(Enemy* );
    pair<double, double> userDifficulty(int, Enemy*);
};

#endif
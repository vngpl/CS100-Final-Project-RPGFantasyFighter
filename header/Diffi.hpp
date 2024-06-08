#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __DIFFICULT_H__
#define __DIFFICULT_H__
#include <utility> // for std::pair

#include "../header/Enemy.hpp"

class Difficulty {
public:
    static void setEasy(Enemy &enemy);
    static void setNormal(Enemy &enemy);
    static void setHard(Enemy &enemy);
    pair<double, double> userDifficulty(int, Enemy&);
};

#endif
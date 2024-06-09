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

    // Static vector to store pointers to enemy objects
    static std::vector<Enemy*> allEnemies;

public:

    static void setEasy();
    static void setNormal();
    static void setHard();
    static void addEnemy(Enemy*);
};

#endif
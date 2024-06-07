#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __DIFFICULT_H__
#define __DIFFICULT_H__
#include <utility> // for std::pair

class Diffculty {
public:
    pair<double, double> setEasy();
    pair<double, double> setNormal();
    pair<double, double> setHard();
};

#endif
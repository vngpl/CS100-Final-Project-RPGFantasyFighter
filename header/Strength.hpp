#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __STRENGTH_H__
#define __STRENGTH_H__

#include "../header/Experience.hpp"

class Strength: public Experience { 
    private:

    public:
        Strength() {}
        int updateCharStrength(int);
};

#endif
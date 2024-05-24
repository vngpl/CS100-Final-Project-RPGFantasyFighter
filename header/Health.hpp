#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef __HEALTH_H__
#define __HEALTH_H__

#include "../header/Experience.hpp"

class Health: public Experience { 
    private:
        
    public:
        Health() {}
        int updateCharHealth(int);
};

#endif
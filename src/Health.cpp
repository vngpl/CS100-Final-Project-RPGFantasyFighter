#include<iostream>
#include<string>

using namespace std;
#include "../header/Health.hpp"
#include "../header/Experience.hpp"

int Health::updateCharHealth(int hpMAX) {
    return hpMAX + 10;
}
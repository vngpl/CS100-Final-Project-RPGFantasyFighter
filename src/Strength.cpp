#include<iostream>
#include<string>

using namespace std;
#include "../header/Strength.hpp"
#include "../header/Experience.hpp"

int Strength::updateCharStrength(int StrengthPoints) {
    return StrengthPoints + 8;
}
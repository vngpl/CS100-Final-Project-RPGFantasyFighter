#include <iostream>
#include <string>

using namespace std;

#include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Monster.hpp"
#include "../header/Difficulty.hpp"

pair<double, double> Difficulty::setEasy() {
    Monster monster("EasyMonster", 100, 5, 100.0); // Example initialization
    double modifiedHealth = monster.getHealth() * 0.5;
    double modifiedAttackStrength = monster.getAttackStrength() * 0.5;
    return {modifiedHealth, modifiedAttackStrength};
}

pair<double, double> Difficulty::setNormal() {
    Monster monster("NormalMonster", 100, 5, 100.0); // Example initialization
    double modifiedHealth = monster.getHealth();
    double modifiedAttackStrength = monster.getAttackStrength();
    return {modifiedHealth, modifiedAttackStrength};
}

pair<double, double> Difficulty::setHard() {
    Monster monster("HardMonster", 100, 5, 100.0); // Example initialization
    double modifiedHealth = monster.getHealth() * 1.5;
    double modifiedAttackStrength = monster.getAttackStrength() * 1.5;
    return {modifiedHealth, modifiedAttackStrength};
}



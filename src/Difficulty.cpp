#include <iostream>
#include <string>

using namespace std;

#include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Difficulty.hpp"

pair<double, double> Difficulty::setEasy() {
    Enemy enemy(MONSTER, 125, 100);
    double modifiedHealth = enemy.getHealth() * 0.5;
    double modifiedAttackStrength = enemy.getAttackStrength() * 0.5;
    return {modifiedHealth, modifiedAttackStrength};
}

pair<double, double> Difficulty::setNormal() {
    Enemy enemy(MONSTER, 125, 100);     
    double modifiedHealth = enemy.getHealth();
    double modifiedAttackStrength = enemy.getAttackStrength();
    return {modifiedHealth, modifiedAttackStrength};
}

pair<double, double> Difficulty::setHard() {
    Enemy enemy(MONSTER, 125, 100);
    double modifiedHealth = enemy.getHealth() * 1.5;
    double modifiedAttackStrength = enemy.getAttackStrength() * 1.5;
    return {modifiedHealth, modifiedAttackStrength};
}


//     Difficulty::userDifficulty() {
//     pair<double, double> stats; // To store the health and attack strength

//     switch (userInput) {
//         case 1:
//             stats = monsterDiff.setEasy();
//             userInput = 0;
//             break;
//         case 2:
//             stats = monsterDiff.setNormal();
//             userInput = 0;
//             break;
//         case 3:
//             stats = monsterDiff.setHard();
//             userInput = 0;
//             break;
//         default:
//             stats = monsterDiff.setEasy();
//             userInput = 0;
//             break;
//     }
//  }
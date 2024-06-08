#include <iostream>
#include <string>

using namespace std;

// #include "../header/Character.hpp"
#include "../header/Enemy.hpp"
#include "../header/Diffi.hpp"

void Difficulty::setEasy(Enemy* enemy) {
    enemy->setHealth(enemy->getHealth() * 0.5);
    enemy->setAttackStrength(enemy->getAttackStrength() * 0.5);
}

void Difficulty::setNormal(Enemy* enemy) {    
    // Stays the same lol
}

void Difficulty::setHard(Enemy* enemy) {
    enemy->setHealth(enemy->getHealth() * 1.5);
    enemy->setAttackStrength(enemy->getAttackStrength() * 1.5);
}

pair<double, double> Difficulty::userDifficulty(int userInput, Enemy* enemy) {
    switch (userInput) {
        case 1:
            setEasy(enemy);
            break;
        case 2:
            setNormal(enemy);
            break;
        case 3:
            setHard(enemy);
            break;
        default:
            setEasy(enemy);
            break;
    }
    return {enemy->getHealth(), enemy->getAttackStrength()};
}
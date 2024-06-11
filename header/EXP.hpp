#include <cmath>
#include <iostream>
#include <string>

// using namespace std;

#ifndef __EXP_H__
#define __EXP_H__

#include "Character.hpp"
#include "EXP.hpp"
#include "Enemy.hpp"

class Experience {
 private:
  int level = 5;
  double exp;  // GIVEN FROM CHARACTER FILE
  int healthXP;
  int strengthXP;
  double expNext;
  int levelMonster;
  int healthMonster;
  int skillPoints = 0;
  Character* character;
  // Enemy* enemy;

 public:
  bool updateLevel();
  double gainExperience(int);
  void pointAssign(int);

  Experience();  // Default constructor
  // ~Experience();
  Experience(int, double, Character*, Enemy*);
  double getNextEXP();
  double getEXP();
  // double getNextEXP();
  int getLevel();
  int getLevelMonster();
  int getHP();
  int getMonsterHealth();
  void setHPMAX(int);
};

#endif
#include <cmath>
#include <iostream>
#include <string>

#ifndef __DIFFICULT_H__
#define __DIFFICULT_H__
#include <vector>

#include "../header/Enemy.hpp"

class Difficulty {
 private:
  // Static vector to store pointers to enemy objects
  std::vector<Enemy*> allEnemies;
  int32_t diffi_level;

 public:
  Difficulty();
  ~Difficulty();
  void setLevel(int32_t);
  bool levelSettled() const;
  void setEasy();
  void setNormal();
  void setHard();
  // static void addEnemy(Enemy*);
  void setEnemies(const std::vector<Enemy*>& enemies);
};

#endif
#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Character.hpp"

class Enemy {
 private:
  int health;
  double attackStrength;
  std::string type;
  int level;

 public:
  Enemy();
  Enemy(int, double, int, const std::string&);
  virtual ~Enemy() = default;

  int getHealth() const;
  int getLevel() const;
  double getAttackStrength() const;
  const std::string& getType() const;

  void setHealth(int);
  void setLevel(int);
  void setAttackStrength(double);
};

#endif
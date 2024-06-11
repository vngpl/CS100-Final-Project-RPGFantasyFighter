#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>

#include "Item.hpp"

class Character {
 private:
  int health;
  double attackStrength;
  int level;
  std::string type;
  int MAX_HEALTH;
  double experience;
  double nextExperience;
  int monstersSlain;
  int coins;
  std::vector<Item*> inventory;

 public:
  Character(int, double, int, const std::string&);
  virtual ~Character();

  // virtual void performSpecialAbility() = 0;

  int getHealth() const;
  int getMaxHealth() const;
  int getLevel() const;
  int getMonstersSlain() const;
  int getCoins() const;
  double getExperience() const;
  double getNextExperience() const;  /// NEW
  double getAttackStrength() const;
  virtual const std::string& getType() const;
  const std::vector<Item*>& getInventoryItems() const;

  void setCoins(int);
  void setHealth(int);
  void setExperience(double);
  void setNextExperience(double);  /// NEW
  void setLevel(int);
  void updateMonsterSlainCount();
  void setAttackStrength(double);

  bool inventoryIsEmpty() const;
  bool hasWeapon() const;
  bool hasPotion() const;
  bool isDead() const;

  void addItem(Item*);
  void useItem(int);
};

#endif

#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include <iostream>
#include <memory>
#include <vector>

#include "Character.hpp"
#include "Display.hpp"
#include "Enemy.hpp"
// #include "Inventory.hpp"

class Battle {
 private:
  int32_t option;
  int32_t itemIntex;
  bool fight_impl(Character* attacker, Enemy* defender);
  bool fight_impl(Enemy* attacker, Character* defender);

 public:
  Battle();
  ~Battle();

  bool fight(Character* player, const std::vector<Enemy*>& enemies);

  // getters
  // int32_t get_option() const;
  // int32_t get_item() const;

  // setters
  void set_option(int32_t op);
  void set_item(int32_t op);

  static float get_rate(int32_t level_a, int32_t level_b);
};

#endif
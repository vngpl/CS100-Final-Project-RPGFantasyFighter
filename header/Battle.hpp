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
  bool fight_impl(Character* attacker, Enemy* defender);
  bool fight_impl(Enemy* attacker, Character* defender);

 public:
  Battle();
  ~Battle();

  bool fight(Character* player, Enemy* enemies);
  void use_item(Character* player, int32_t itemIndex);

  static float get_rate(int32_t level_a, int32_t level_b);
};

#endif
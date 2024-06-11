#include "../header/Battle.hpp"

#include <cstdlib>
#include <ctime>

#include "../header/Display.hpp"

Battle::Battle() {}
Battle::~Battle() {}

bool Battle::fight_impl(Character* attacker, Enemy* defender) {
  int32_t atk_level = attacker->getLevel();
  int32_t def_level = defender->getLevel();
  const float atk_rate = get_rate(atk_level, def_level);
  double atk_strength = attacker->getAttackStrength();
  atk_strength = std::max<float>(1.0, atk_strength * atk_rate);
  int32_t def_health = defender->getHealth();
  int32_t new_health = def_health - static_cast<int32_t>(atk_strength);
  defender->setHealth(static_cast<int32_t>(new_health));
  if (new_health < 0) {
    return true;  // defender is dead
  }
  return false;
}

bool Battle::fight_impl(Enemy* attacker, Character* defender) {
  int32_t atk_level = attacker->getLevel();
  int32_t def_level = defender->getLevel();
  const float atk_rate = get_rate(atk_level, def_level);
  double atk_strength = attacker->getAttackStrength();
  atk_strength = std::max<float>(1.0, atk_strength * atk_rate);
  int32_t def_health = defender->getHealth();
  int32_t new_health = def_health - static_cast<int32_t>(atk_strength);
  defender->setHealth(new_health);
  if (new_health <= 0) {
    return true;  // defender is dead
  }
  return false;
}

// Return true if the player is dead
bool Battle::fight(Character* player, Enemy* enemy) {
  bool anyone_dead = false;
  bool flip = true;
  while (anyone_dead) {
    if (flip) {
      anyone_dead = fight_impl(player, enemy);
    } else {
      anyone_dead = fight_impl(enemy, player);
      if (anyone_dead) {
        return true;
      }
    }
    flip = !flip;  // role switching
  }
  return false;
}

void Battle::use_item(Character* player, int32_t itemIndex) {
  player->useItem(itemIndex);
}

float Battle::get_rate(int32_t level_a, int32_t level_b) {
  std::srand(std::time(nullptr));
  float rate =
      0.95 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (1.05 - 0.95)));
  return rate;
}

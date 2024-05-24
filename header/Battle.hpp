#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include <iostream>
#include <vector>

#include "Character.hpp"
#include "Enemy.hpp"

class Battle {
 private:
  Character* player;
  std::vector<Enemy*> enemies;
  std::vector<std::string> items;

 public:
  Battle(Character& player, Enemy& enemy);
  Battle(Character& player, const std::vector<Enemy&>& enemies);
  ~Battle();

  void startBattle();
  void fight(Character& attacker, Enemy& defender);
  void fight(Enemy& attacker, Character& defender);
  void useItems(Character& character);
  void run();

  bool isPlayerDead() const;
  bool areEnemiesDead() const;

  void handlePostBattleActions(bool playerWon);
};

#endif
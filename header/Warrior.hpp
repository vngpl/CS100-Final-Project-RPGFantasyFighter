#ifndef __WARRIOR_HPP_
#define __WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public Character {
 public:
  Warrior() : Character(125, 100, 5, "WARRIOR") {}
  // void performSpecialAbility() override;
};

#endif
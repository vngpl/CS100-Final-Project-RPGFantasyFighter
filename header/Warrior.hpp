#ifndef __WARRIOR_HPP_
#define __WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public Character {
   public:
        Warrior() : Character(125, 100, 1, "WARRIOR") { }
};

#endif
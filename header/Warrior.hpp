#ifndef __WARRIOR_HPP_
#define __WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public Character {
   public:
        Warrior();
        std::string getType() const override;
};

#endif
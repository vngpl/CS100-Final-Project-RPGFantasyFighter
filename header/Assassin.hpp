#ifndef __ASSASSIN_HPP_
#define __ASSASSIN_HPP_

#include "Character.hpp"

class Assassin : public Character {
    public:
        Assassin() : Character(90, 120, 1, "ASSASSIN") {}
        void performSpecialAbility() override;
};

#endif

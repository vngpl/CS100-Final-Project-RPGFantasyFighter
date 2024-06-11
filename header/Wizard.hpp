#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include "Character.hpp"

class Wizard : public Character {
   public:
        Wizard() : Character(100, 100, 1, "WIZARD") {}
        void performSpecialAbility() override;
};

#endif
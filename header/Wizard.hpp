#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include "Character.hpp"

class Wizard : public Character {
   public:
        Wizard();
        void performSpecialAbility() override;
};

#endif
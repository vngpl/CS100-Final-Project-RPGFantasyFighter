#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include "Character.hpp"

class Wizard : public Character {
   public:
        Wizard();
        std::string getType() const override;
};

#endif
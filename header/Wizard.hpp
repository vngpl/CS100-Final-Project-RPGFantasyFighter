#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include "Character.hpp"

class Wizard : public Character {
    private:

    public:
        Wizard(const std::string&, int, double, double);
        void attack(Character&) override;
        // IMPLEMENT ATTACK FUNCTIONS
};

#endif